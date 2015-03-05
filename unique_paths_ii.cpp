class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        int res;
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        int **dp = new int*[m];
        for(int i=0;i<m;i++) { dp[i] = new int[n]; }
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {   
                if(obstacleGrid[i][j]==1) dp[i][j]=0;
                else if(i==0&&j==0) dp[i][j]=1;
                else if(i==0 &&j!=0)
                    dp[i][j] = obstacleGrid[i][j-1]==1?0:dp[i][j-1];
                else if(j==0 &&i!=0)
                    dp[i][j] = obstacleGrid[i-1][j]==1?0:dp[i-1][j];
                else
                    dp[i][j] = (obstacleGrid[i][j-1]==1?0:dp[i][j-1]) + (obstacleGrid[i-1][j]==1?0:dp[i-1][j]);
                
            }
        }
        
        res = dp[m-1][n-1];
        for(int i=0;i<m;i++)
        {
            delete [] dp[i];
        }
        return res;
    }
};