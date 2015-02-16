class Solution {
public:
    int numTrees(int n) {
        int *res;
        res = new int[n+1];
        
        if(n<1) return 0;
        
        for(int i=0;i<=n;i++)
        {
            if(i==1||i==0) {res[i] = 1;continue;}
            res[i] = 0;
            for(int j=1;j<=i;j++)
            {
                res[i]+=res[j-1]*res[i-j];
            }
        }
        
        int r = res[n];
        delete [] res;
        return r;
    }
};