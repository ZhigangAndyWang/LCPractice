class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> res;
        res.clear();
        res.push_back(0);
        if(n==0) return res;
        
        for(int k=0;k<n;k++)
        {
            int p = pow(2,k);
            for(int i=p;i<2*p;i++)
            {
                int j = p-(i-p)-1;
                res.push_back(p+res[j]);
            }
        }
        return res;
    }
};