class Solution {
private:
    //backtracking for searching chars
    bool search( vector<vector<char>>& board,int i,int j, string word,vector<vector<bool> > &mask){
        if(word.size()==0) return true;
        int m = board.size();
        int n = board[0].size();
        
        if(i-1>=0 && mask[i-1][j] == false && board[i-1][j] == word[0]){
            mask[i-1][j] = true;
            if( search(board,i-1,j, word.substr(1),mask) ) return true;
            mask[i-1][j] = false;
        }
                
        if(i+1<m && mask[i+1][j] == false && board[i+1][j] == word[0]){
            mask[i+1][j] = true;
            if( search(board,i+1,j, word.substr(1),mask) ) return true;
            mask[i+1][j] = false;
        }        
        if(j<n && mask[i][j+1] == false && board[i][j+1] == word[0]){
            mask[i][j+1] = true;
            if( search(board,i,j+1, word.substr(1),mask) ) return true;
            mask[i][j+1] = false;
        }        
        if(j-1>=0 && mask[i][j-1] == false && board[i][j-1] == word[0]){
            mask[i][j-1] = true;
            if( search(board,i,j-1, word.substr(1),mask) ) return true;
            mask[i][j-1] = false;
        }
        return false;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        if( m==0 || n==0) return false;
        
        
        
        for(int i = 0; i<m ;++i){
            for(int j=0; j<n; ++j){
                if(board[i][j] == word[0]){
                    if(word.size()==1 ) return true;
                    vector<vector<bool> > mask(m, vector<bool>(n,false));
                    mask[i][j] = true;
                    if( search(board,i,j,word.substr(1),mask)) return true;
                }
            }
        }
        return false;
    }
};