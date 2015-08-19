class Solution {
public:
    int minCut(string s) {
        int n = s.size();
        
        bool P[n][n]; //if it is palindrome
        memset(P,false,n*n*sizeof(bool));
        
        int dp[n]; //dp[i] means the #of shortest cut from i to n-1;
        
        for(int i = n-1; i >=0 ; i--){
            
            if(i==n-1) {dp[n-1] = 0; continue;}
            dp[i] = INT_MAX;
            
            for(int j = i; j < n; j++){
                if ( s[i] == s[j] && (j-i < 2 || P[i+1][j-1])){ // i-j is palindrome
                    P[i][j] = true;
                    
                    if( j == n-1 ) dp[i] = 0;
                    else dp[i] = min(dp[i], 1+dp[j+1]);
                }
            }
        }
        return dp[0];
    }
};