class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix.size();
        if(!m) return 0;
        int n = matrix[0].size();
        if(!n ) return 0;
        vector<vector<int>> ones(m,vector<int>(n,0));
        
        for(int i = 0; i < m ; i++){
            for(int j = 0; j < n; j++){
                if(matrix[i][j] == '0') ones[i][j] = 0;
                else{
                    if(j!=0 && matrix[i][j-1] == '1'){
                        ones[i][j] = ones[i][j-1]-1;
                        continue;
                    }
                    for(int k = j; k < n && matrix[i][k] == '1'; k++){
                        ones[i][j] ++;
                    }
                }
            }
        }
        int maxSize = 0;
        
        for(int i = 0; i < m ; i++){
            for(int j = 0; j < n; j++){
                int recWidth = INT_MAX, curRecSize;
                for(int k = i; k < m && ones[k][j]>0 ; k++){
                    recWidth = min(recWidth,ones[k][j]);
                    curRecSize = (k-i+1)*recWidth;
                    maxSize = max(maxSize,curRecSize);
                }
            }
        }
        
        return maxSize;
    }
};