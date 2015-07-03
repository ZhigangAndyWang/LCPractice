class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();
        int dp[m+1][n+1];
        memset(dp,0,(m+1)*(n+1)*sizeof(int));
        
        for(int i = 0; i < m+1; i++){
            dp[i][0] = i;
        }
        for(int i = 0; i < n+1; i++){
            dp[0][i] = i;
        }
        
        for(int i = 1; i < m+1 ; i++){
            for(int j = 1; j < n+1; j++){
                if(word1[i-1] == word2[j-1])
                    dp[i][j] = dp[i-1][j-1];
                else{
                    int a = dp[i-1][j-1]+1; //case of word2[j] is substituted
                    int b = dp[i][j-1] + 1; //word2[j] is inserted
                    int c = dp[i-1][j] + 1; //word1[i] is deleted
                    dp[i][j] = min(a,min(b,c));
                }
            }
        }
        return dp[m][n];
    }
};