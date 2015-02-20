class Solution {
public:
    int findMin(vector<int> &num) {
        int begin=0,end=num.size()-1;

        if(end==begin) return num[begin];
        
        while(end>begin)
        {   
            if(num[begin]<num[end]) return num[begin];
            if(end-begin==1&&num[begin]>num[end]) return num[end];
            int idx = begin+(end-begin)/2;
            if(num[begin]>num[idx])
            {
                end = idx;
            }
            else
            {
                begin = idx;
            }
        }
    }
};