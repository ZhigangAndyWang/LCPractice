class Solution {
public:
    void setZeroes(vector<vector<int> > &matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        
        unordered_set<int > row,col;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]==0){
                    row.insert(i);col.insert(j);
                }
            }
        }
        
        for(auto it=row.begin();it!=row.end();it++){
            int rn = *it;
            for(int j=0;j<n;j++) matrix[rn][j]=0;
        }
        for(auto it=col.begin();it!=col.end();it++){
            int cn = *it;
            for(int i=0;i<m;i++) matrix[i][cn]=0;
        }
    }
};