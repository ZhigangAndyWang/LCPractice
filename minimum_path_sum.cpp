#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int> > &grid) {
        int m = grid.size();
        int n = grid[0].size();
        int **dp = new int*[m];
        for(int i=0;i<m;i++) {dp[i] = new int[n];}
        
        for(int i=m-1;i>=0;i--)
        {
            for(int j=n-1;j>=0;j--)
            {
                if(i==m-1&&j==n-1) dp[i][j] = grid[m-1][n-1];
                else if(i==m-1&&j!=n-1) dp[i][j] = dp[i][j+1] + grid[i][j];
                else if(j==n-1&&i!=m-1) dp[i][j] = dp[i+1][j] + grid[i][j];
                else 
                {
                    int a = dp[i][j+1];
                    int b = dp[i+1][j];
                    dp[i][j] = min(a,b)+grid[i][j];
                }
            }
        }
        return dp[0][0];
    }
};


int main(){
    Solution s;
    vector<vector<int> > grid;
    int a1[3] = {1,3,1};
    vector<int> t(a1,a1+3);
    grid.push_back(t);
    int a2[3] = {1,5,1};
    vector<int> t1(a2,a2+3);
    grid.push_back(t1);
    int a3[3] = {4,2,1};
    vector<int> t2(a3,a3+3);
    grid.push_back(t2);
    int c = s.minPathSum(grid);
    cout << c;
    return 0;
}
