class Solution {
private:
    bool isValid(vector<vector<char>>& board, int irow, int icol){
        char val = board[irow][icol];
        if(val-'0'<1 || val-'0'>9) return false;
        
        // check row & col
        for(int i=0; i<9; i++) {
            if(board[irow][i]==val && i!=icol) return false;
            if(board[i][icol]==val && i!=irow) return false;
        }
        
        //check 3x3 box
        int irow0 = irow/3*3;
        int icol0 = icol/3*3;
        for(int i=irow0; i<irow0+3; i++) {
            for(int j=icol0; j<icol0+3; j++) {
                if(board[i][j]==val && (i!=irow || j!=icol)) return false;
            }
        }

        return true;
    }
    bool backtracking(vector<vector<char>>& board, int row, int col){
        if(row == 9) return true;
        
        int nextRow,nextCol;
        if(col == 8){
            nextRow = row+1;
            nextCol = 0;
        }
        
        else{
            nextRow = row;
            nextCol = col+1;
        }
        
        if(board[row][col] != '.'){
            if(isValid(board,row,col)){
                return backtracking(board,nextRow,nextCol);
            }
            else
                return false;
        }
        //board[row][col] is '.'
        for (int i = 1; i<=9; i++){
            char c = '0'+i;
            board[row][col] = c;
            if (isValid(board,row,col) && backtracking(board,nextRow,nextCol)) return true;
        }
        board[row][col] = '.'; // important
        return false;
    }
public:
    void solveSudoku(vector<vector<char>>& board) {
        if(board.size()<9 || board[0].size()<9) return;
        backtracking(board,0,0);
    }
};