class Solution {
private:
    void dfs(vector<vector<char>>& grid, vector<vector<bool> > &visited, int i, int j){
        int m = grid.size();
        int n = grid[0].size();
        
        visited[i][j] = true;
        
        if ( i+1 < m && grid[i+1][j] == '1' && visited[i+1][j] == false){
            dfs(grid,visited,i+1,j);
        }
        if ( j+1 < n && grid[i][j+1] == '1' && visited[i][j+1] == false){
            dfs(grid,visited,i,j+1);
        }
        if ( i-1 >= 0 && grid[i-1][j] == '1' && visited[i-1][j] == false){
            dfs(grid,visited,i-1,j);
        }
        if ( j-1 >=0 && grid[i][j-1] == '1' && visited[i][j-1] == false){
            dfs(grid,visited,i,j-1);
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int res = 0;
        int m = grid.size();
        if ( m == 0 ) return res;
        int n = grid[0].size();
        if ( n == 0 ) return res;
        
        vector<vector<bool> > visited(m,vector<bool>(n,false));
        
        for (int i = 0; i < m ; i++){
            for (int j = 0; j < n; j++){
                if (grid[i][j] == '1' && visited[i][j] == false){
                    dfs(grid,visited,i,j);
                    res++;
                }
            }
        }
        
        return res;
    }
};