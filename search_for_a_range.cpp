class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) 
    {
        vector<int> ret;
        ret.push_back(-1);
        ret.push_back(-1);

        int start=0,end=n-1,mid;
        while(end>=start)
        {
            mid = start+(end-start)/2;
            if(A[start]==target && A[end]==target)
            {
                ret[0] = start;
                ret[1] = end;
                return ret;
            }
            if(A[mid]<target){start=mid+1;}
            else if(A[mid]>target){end=mid-1;}
            else //A[mid]==target
            {
                if(A[end]==target) start++;
                else end--;
            }
        }
        return ret;
    }
};