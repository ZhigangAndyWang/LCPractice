class Solution {
public:
    void setZeroes(vector<vector<int> > &matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        
        int rr=-1,cc=-1;
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]==0){
                    if(rr==-1&&cc==-1){
                        rr = i; cc = j;
                    }
                    else{
                        matrix[i][cc] = 0;
                        matrix[rr][j] = 0;
                    }
                }
            }
        }
        
        if(rr == -1&& cc == -1) return;
        
        for(int i=0;i<m;i++){
            if(matrix[i][cc] == 0 && i!=rr){
                for(int j=0;j<n;j++){
                    matrix[i][j] = 0;
                }
            }
            matrix[i][cc] = 0;
        }
        for(int j=0;j<n;j++){
            if(matrix[rr][j] == 0 && j!=cc){
                for(int i=0;i<m;i++){
                    matrix[i][j] = 0;
                }
            }
            matrix[rr][j] = 0;
        }
    }
};