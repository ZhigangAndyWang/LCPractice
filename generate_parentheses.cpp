class Solution {
public:
    vector<string> generateParenthesis(int n)
    {
        vector<string> res;
        if(!n) return res;
        
        backtracking(0,0,0,"",res,n);
    }
    
    void backtracking(int left,int right,int sum,string cur,vector<string> &res,int n)
    {
        if(left==n&&right==n) 
        {
            res.push_back(cur);
            return;
        }
        if(left<right) return; //sum<0, invalid parentheses
        
        if(left<n) backtracking(left+1,right,sum+1,cur+"(",res,n);
        if(right<n) backtracking(left,right+1,sum-1,cur+")",res,n);
    }
};