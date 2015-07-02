
class Solution {
private:
    bool validPos(vector<int> &cols, int curRow, int icol){
        for(int i = 0; i < curRow; i++){
            if( cols[i] == icol )return false;
            if( abs(cols[i] - icol) == curRow-i ) return false;
        }
        return true;
    }
    void backtracking(int &res, int curRow, vector<int> &cols,int n){
        if (curRow == n){
            //solution found
            res++;
            return;
        }
        
        for(int i = 0; i < n; i++){
            if (validPos(cols,curRow,i) ){
                cols[curRow] = i;
                backtracking(res, curRow+1, cols, n);
            }
        }
    }
public:
    int totalNQueens(int n) {
        int res = 0;
        int curRow = 0;
        vector<int> cols(n,-1);
        
        backtracking(res,curRow,cols,n);
        
        return res;
    }
};