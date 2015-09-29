class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        if(!m) return false;
        int n = matrix[0].size();
        if(!n) return false;
        
        int j = n-1;
        
        for(int i = 0 ; i < m; i++){
            while( j >= 0 ){
                if(matrix[i][j] == target) return true;
                if(matrix[i][j] > target) j--;
                if(matrix[i][j] < target) break;
            }
        }
        
        return false;
    }
};