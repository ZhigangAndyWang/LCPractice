class Solution {
private:
    bool validPos(vector<int> &cols, int curRow, int icol){
        for(int i = 0; i < curRow; i++){
            if( cols[i] == icol )return false;
            if( abs(cols[i] - icol) == curRow-i ) return false;
        }
        return true;
    }
    void backtracking(vector<vector<string> > &res, vector<string> &sol, int curRow, vector<int> &cols,int n){
        if (curRow == n){
            //solution found
            res.push_back(sol);
            return;
        }
        
        for(int i = 0; i < n; i++){
            if (validPos(cols,curRow,i) ){
                string s(n,'.');
                s[i] = 'Q';
                sol.push_back(s);
                cols[curRow] = i;
                backtracking(res, sol, curRow+1, cols, n);
                sol.pop_back();
            }
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string> > res;
        vector<string> sol;
        int curRow = 0;
        vector<int> cols(n,-1);
        
        backtracking(res,sol,curRow,cols,n);
        
        return res;
    }
};