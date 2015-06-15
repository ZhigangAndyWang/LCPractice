class Solution {
public:
    bool wordBreak(string s, unordered_set<string>& wordDict) {
        if(s.size()==0) return false;
        int n = s.size();
        
        vector<vector<bool> > dp(n,vector<bool>(n,false));
        
        for(int i=0;i < n; ++i){
            for(int j=i;j<n; ++j){
                if ( wordDict.find(s.substr(i,j-i+1) ) != wordDict.end() ){
                    dp[i][j] = true;
                }
            }
        }
        
        int i = 0;
        for(int j=i;j<n; ++j){
            for(int k=i;k<j; ++k){
                if(!dp[i][j] && dp[i][k] && dp[k+1][j]){
                    dp[i][j] = true;
                }
            }
        }
        return dp[0][n-1];
    }
};