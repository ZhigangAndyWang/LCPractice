class Solution {
    
public:
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        vector<vector<int> > res;
        sort(S.begin(),S.end());
        // if(S.empty()) return res;
        res.push_back(vector<int>(0));
        vector<int> cur;
        backtracking(cur,res,0,S);
        return res;
    }
    void backtracking(vector<int> &cur, vector<vector<int>>& res, int start,vector<int> &S) 
    {
        if (start == S.size()) return;
        for (int i=start; i<S.size(); i++) 
        {
            if  (i == start || S[i] != S[i-1]) 
            {
                cur.push_back(S[i]);
                res.push_back(cur);
                backtracking(cur,res,i+1,S);
                cur.pop_back();
            }
        }
    }
};