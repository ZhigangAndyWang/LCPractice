class Solution {
    unordered_map<int,int> used;
public:
    vector<vector<int> > permuteUnique(vector<int> &num) {
        vector<vector<int> > res;
        if(!num.size()) return res;
        
        sort(num.begin(),num.end());
        
        for(int i=0;i<num.size();i++) used[i] = 0;
        vector<int> cur;
        backtracking(cur,res,num);
        return res;
    }
    
    void backtracking(vector<int> &cur, vector<vector<int> > &res, vector<int> num)
    {
        if(cur.size()==num.size()) {
            res.push_back(cur);
            return;
        }
        for(int i=0;i<num.size();i++)
        {
            if(used[i]==0)
            {
                //the catch of the problem
                if(i==0 || used[i-1] ==1 || num[i]!=num[i-1])
                {
                    cur.push_back(num[i]);
                    used[i] = 1;
                    backtracking(cur,res,num);
                    cur.pop_back();
                    used[i] = 0;
                }
            }
        }
    }
};  