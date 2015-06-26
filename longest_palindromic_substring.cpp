class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        if(n<=1) return s;
        
        
        int maxL = 0;
        int start = 0;
        int end = 0;
        
        //determines from i to j is palindrom or not
        
        int dp[n][n];  
        memset(dp, 0, n*n*sizeof(bool));  
            
        // vector<vector<bool> > dp(n,vector<bool>(n,false)); //failed memory exceed
        
        for(int i = 0; i<n; i++){
            for(int j = 0; j <= i-1; j++){
                dp[j][i] = (s[j] == s[i]) && (i-j<2 || dp[j+1][i-1]);
                if(dp[j][i] && (i-j+1 > maxL)){
                    maxL = i-j+1;
                    start = j;
                    end = i;
                }
            }
            dp[i][i] = true;
        }
        
        return s.substr(start,end-start+1);
        
    }
};