class Solution {
public:
    int numDistinct(string s, string t) {
        int m = s.size();
        int n = t.size();
        if(m == 0 || n == 0) return 0;
        if(n>m) return 0;
        int res = 0;
        vector<vector<int> >  dp(m+1,vector<int>(n+1,0));
        
        for(int i = 1; i <= m ; ++i){
            for(int j = 1; j <= min(i,n); ++j){
                if( j == 1 && i == 1){
                    dp[i][j] = (s[0] == t[0])? 1:0;
                    continue;
                }
                if( s[i-1] == t[j-1] ){
                    if(j == 1){
                        dp[i][j] = 1+dp[i-1][j];
                    }
                    else
                        dp[i][j] = dp[i-1][j-1] + dp[i-1][j];    
                }
                else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        return dp[m][n];
        
    }
};