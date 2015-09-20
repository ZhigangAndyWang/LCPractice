class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int m = s1.size();
        int n = s2.size();
        if (s3.size()!= m+n) return false;
        if ( m==0 ) return s2 == s3;
        if ( n==0 ) return s1 == s3;
        
        // bool dp[m+1][n+1];
        vector<vector<bool> > dp(m+1,vector<bool>(n+1,false));
        dp[0][0] = true;
        //initilize 1st row and column
        for(int i = 1; i < m+1 ; i++){
            dp[i][0] = dp[i-1][0] && s1[i-1] == s3[i-1];
        }
        for(int j = 1; j < n+1 ; j++){
            dp[0][j] = dp[0][j-1] && s2[j-1] == s3[j-1];
        }
        //dp
        for(int i = 1; i < m+1 ; i++){
            for(int j = 1; j < n+1 ; j++){
                if(s3[i+j-1] == s1[i-1])
                    dp[i][j] = dp[i][j] || dp[i-1][j];
                if(s3[i+j-1] == s2[j-1]){
                    dp[i][j] = dp[i][j] || dp[i][j-1];
                }
            }
        }
        
        return dp[m][n];
    }
};