class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        if(!triangle.size()) return 0;
        int row = triangle.size();
        vector<int> dp(triangle[row-1].size());
        
        for(int i = row-1; i >= 0 ; i--)
        {
            for(int j = 0;j < triangle[i].size();j++)
            {
                if(i == row-1) {dp[j] = triangle[i][j];continue;}
                dp[j] = min(dp[j],dp[j+1])+triangle[i][j];
            }
        }
        return dp[0];
    }
};