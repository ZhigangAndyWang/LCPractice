class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if(matrix.empty() || matrix[0].empty()) return 0;

        vector<vector<int> > m(matrix.size(),vector<int>(matrix[0].size(),0));
        int maxSize = 0;
        for(int i=0; i < matrix.size(); i++){
            for(int j=0; j < matrix[0].size() ;j++){
                int k = matrix[i][j]-'0';
                if(i == 0 || j == 0){
                    m[i][j] = k;
                }
                else if( matrix[i][j] == '1'){
                    m[i][j] = min( m[i-1][j-1],min( m[i-1][j],m[i][j-1] ) )+1;
                }
                maxSize = max(maxSize,m[i][j]);
            }
        }
        
        return maxSize*maxSize;
    }
};