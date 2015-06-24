class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        if (!m) return;
        int n = board[0].size();
        if (m <= 2 || n <=2) return;
        
        queue<pair<int,int>> q;
        vector<vector<bool>> visited(m,vector<bool>(n));
        
        //find 'O' from outside
        //1st column & last column
        for(int i = 0; i < m ; i++){
            if (board[i][0] == 'O' && visited[i][0] == false){
                visited[i][0] = true;
                q.push(make_pair(i,0));
            }
            if (board[i][n-1] == 'O' && visited[i][n-1] == false){
                visited[i][n-1] = true;
                q.push(make_pair(i,n-1));
            }
        }
        //1st row and last row
        for(int j = 0; j < n ; j++){
            if(board[0][j] == 'O' && visited[0][j] == false){
                visited[0][j] = true;
                q.push(make_pair(0,j));
            }
            if(board[m-1][j] == 'O' && visited[m-1][j] == false){
                visited[m-1][j] = true;
                q.push(make_pair(m-1,j));
            }
        }
        
        while(!q.empty()){
            pair<int,int> p = q.front();
            q.pop();
            int i = p.first, j = p.second;
            if( i-1 >= 0 && visited[i-1][j] == false && board[i-1][j] == 'O'){
                visited[i-1][j] = true;
                q.push(make_pair(i-1,j));
            }
            if( i+1 < m && visited[i+1][j] == false && board[i+1][j] == 'O'){
                visited[i+1][j] = true;
                q.push(make_pair(i+1,j));
            }
            if( j-1 >= 0 && visited[i][j-1] == false && board[i][j-1] == 'O'){
                visited[i][j-1] = true;
                q.push(make_pair(i,j-1));
            }
            if( j+1 < n && visited[i][j+1] == false && board[i][j+1] == 'O'){
                visited[i][j+1] = true;
                q.push(make_pair(i,j+1));
            }
        }
        
        for(int i = 0; i < m ; ++i){
            for (int j = 0; j<n ; ++j){
                if(visited[i][j] == false && board[i][j] == 'O')
                    board[i][j] ='X';
            }
        }
    }
};