class Solution {
public:
    vector<vector<int> > combine(int n, int k) {
        vector<vector<int> > res;
        if(n<=0||!k) return res;
        
        vector<int> flags(n+1,0);
        vector<int> cur;
        
        backtracking(n,k,cur,res,flags);
        return res;
    }
    
    void backtracking(int n,int k,vector<int> &cur,vector<vector<int>> &res,vector<int> flags)
    {
        if(cur.size()==k)
        {
            res.push_back(cur);
            return;
        }
        for(int i=1;i<=n;i++)
        {
            if(cur.size()==0 || (flags[i]==0 && i > cur.back() ) )
            {
                cur.push_back(i);
                flags[i] = 1;
                backtracking(n,k,cur,res,flags);
                flags[i] = 0;
                cur.pop_back();
            }
        }
    }
};