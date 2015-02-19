class Solution {
public:
    int findPeakElement(const vector<int> &num) {
        for(int i=0;i<num.size();i++)
        {
            int n = num.size();
            if(n==1) return 0;
            
            int front = -1;
            int end = n;
            
            
            while(front-end<0)
            {
                int mid = (end+front)/2;
                if(front+1==end)
                {
                    if(num[front]<num[end]) return end;
                    else return front;
                }
                
                if(mid==0)
                {
                    if(num[0]==INT_MIN||num[0]<=num[1]) {front=0;continue;}
                    if (num[0]>num[1]) return 0;
                }
                if(mid==n-1)
                {
                    if(num[n-1]==INT_MIN||num[n-1]<=num[n-2]) {end=n-1;continue;}
                    if(num[n-1]>num[n-2]) return n-1;
                }
                if(num[mid]>num[mid-1]&&num[mid]>num[mid+1]) return mid;
                else if(num[mid-1]>=num[mid])
                {
                    end = mid;
                }
                else if(num[mid]<=num[mid+1])
                {
                    front = mid;
                }
                else
                    return -1;
            }
            return -1;
        }
    }
};