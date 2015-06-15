class Solution {
private:
    void backtracking(vector<vector<int> > &res, vector<int> &cur, int sum, int k, int n){
        
        if(cur.size() > k || sum > n) return;
        if(cur.size() == k && sum < n) return;
        
        if(sum == n && cur.size() == k){
            res.push_back(cur);
            return;
        }
        //(sum < n)
        int tail = (cur.size()==0)? 0:cur.back();
        for(int i = tail+1; i<10; i++){
            cur.push_back(i);
            backtracking(res,cur,sum+i,k,n);
            cur.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int> > res;
        if( k>9 || n<k || n>45) return res;
        
        vector<bool> mask(9,false);
        int sum = 0;
        vector<int> cur;
        
        backtracking(res,cur,sum,k,n);
        return res;
    }
};