class Solution {
public:
    int numDecodings(string s) {
        int res = 0;
        if(s.empty()) return 0;
        
        int n = s.size();
        
        vector<int> dp(n+1,1);
        int cn = s[0] - '0';
        dp[1] = (cn>=1 && cn<=9)? 1:0;
        
        for(int i = 2; i<n+1 ; i++){
            int c1 = s[i-2] - '0';
            int c2 = s[i-1] - '0';
            if(c2 == 0){
                if(c1 == 1 || c1 == 2){
                    dp[i] = dp[i-2];
                    continue;
                }
                else{
                    return 0;
                }
            }
            else if( c1 == 0 || 10*c1 + c2 > 26){
                dp[i] = dp[i-1]; 
            }
            else{
                dp[i] = dp[i-1] + dp[i-2];
            }
        } 
        
        return dp[n];
        
    }
};