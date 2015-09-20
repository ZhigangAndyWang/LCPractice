class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m = dungeon.size();
        if(!m) return 1;
        int n = dungeon[0].size();
        
        vector<vector<int> > dp(m,vector<int>(n,0));
        dp[m-1][n-1] = max(0,-dungeon[m-1][n-1])+1;
        
        for(int i = m-1; i>=0; i--){
            for(int j = n-1; j >= 0; j--){
                if(i==m-1 && j== n-1) continue;
                bool rightCell = false;
                int min_to_right = INT_MAX;
                if(j!=n-1){
                    rightCell = true;
                    min_to_right = std::max(1,dp[i][j+1] - dungeon[i][j]);
                }
                bool downCell = false;
                int min_to_down = INT_MAX;
                if(i!=m-1){
                    downCell = true;
                    min_to_down = std::max(1,dp[i+1][j] - dungeon[i][j]);
                }
                
                int minHealth = min(min_to_down,min_to_right);
                dp[i][j] = minHealth;
            }
        }
        return dp[0][0];
    }
};