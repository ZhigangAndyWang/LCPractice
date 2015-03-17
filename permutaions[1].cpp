class Solution {
    unordered_map<int,int> used;
public:
    vector<vector<int> > permute(vector<int> &num) {
        vector<vector<int> > res;
        if(!num.size()) return res;
        
        for(int i=0;i<num.size();i++) used[i] = 0;
        vector<int> cur;
        backtracking(cur,res,num);
        return res;
    }
    void backtracking(vector<int> &cur, vector<vector<int> > &res, vector<int> &num)
    {
        if(cur.size()==num.size())
        {
            res.push_back(cur);
            return;
        }
        for(int i=0;i<num.size();i++)
        {
            if(used[i]==0)
            {
                cur.push_back(num[i]);
                used[i] = 1;
                backtracking(cur,res,num);
                cur.pop_back();
                used[i] = 0;
            }
        }
    }
};