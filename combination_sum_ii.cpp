class Solution {
private:
    unordered_map<int,bool> index_used;
    void backtracking(vector<int> &cur,int &cur_sum,int start,vector<vector<int> > &res,vector<int> &num,int target)
    {
        if(cur_sum>target) return;
        if(cur_sum == target)
        {
            res.push_back(cur);
            return;
        }
        //cur_sum < target
        for(int i=start;i<num.size();i++)
        {
            // NOTE : this condition helps neglecting making identical sets
            //  this is the catch of this question
            if(i==start || num[i]!=num[i-1] )
            {
                cur.push_back(num[i]);
                // index_used[i] = true;
                cur_sum += num[i];
                backtracking(cur,cur_sum,i+1,res,num,target);
                // index_used[i] = false;
                cur_sum -= num[i];
                cur.pop_back();
            }
        }
    }
public:
    vector<vector<int> > combinationSum2(vector<int> &num, int target) {
        vector<vector<int> > res;
        if(!num.size()) return res;
        sort(num.begin(),num.end());
        
        for(int i=0;i<num.size();i++) index_used[i] = false;
        
        vector<int> cur;
        int cur_sum = 0;
        backtracking(cur,cur_sum,0,res,num,target);
        return res;
    }
};