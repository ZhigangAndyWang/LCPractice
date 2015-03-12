class Solution {
private:
    void backtracking(vector<vector<int >> &res,vector<int> &cur, vector<int> &S)
    {
        res.push_back(cur);
        for(auto it=S.begin();it!=S.end();it++)
        {
            if(cur.empty() || *it>cur.back())
            {
                cur.push_back(*it);
                backtracking(res,cur,S);
                cur.pop_back();
            }
        }
    }
public:
    vector<vector<int> > subsets(vector<int> &S) {
        vector<vector<int >> res;
        vector<int> cur;
        
        backtracking(res,cur,S);
        return res;
    }
};