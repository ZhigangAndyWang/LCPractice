class Solution {
private:
    void backtracking(vector<int> &cur,int &sum,vector<vector<int>> &res,vector<int> &candidates,int target)
    {
        if(sum==target)
        {
            res.push_back(cur);
        }
        else if(sum>target) return;
        else
        {
            for(int i=0;i<candidates.size();i++)
            {
                if(!cur.size()||candidates[i]>=cur.back())
                {
                    cur.push_back(candidates[i]);
                    sum += candidates[i];
                    backtracking(cur,sum,res,candidates,target);
                    sum -= candidates[i];
                    cur.pop_back();
                }
            }
        }
    }
    
public:
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        vector<vector<int>> res;
        if(candidates.size()==0) return res;
        
        vector<int> cur;
        int sum = 0;
        backtracking(cur,sum,res,candidates,target);
        return res;
    }
    
    
};