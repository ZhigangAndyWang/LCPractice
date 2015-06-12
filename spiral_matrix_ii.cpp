class Solution {

public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int> > res(n, vector<int>(n, 0));
        
        if (n == 0 ) return res;
        int i = 0; 
        int j = 0;
        int k = 1;
        
        res[0][0] = k++;
        
        while( k <= n*n){
            while( j+1 < n && res[i][j+1] == 0){ //going right
                res[i][++j] = k++;
            }
            while ( i+1 < n && res[i+1][j] == 0){ //going down
                res[++i][j] = k++;
            }
            while ( j-1 >= 0 && res[i][j-1] == 0){ //left
                res[i][--j] = k++;
            }
            while ( res[i-1][j] == 0){ //up
                res[--i][j] = k++;
            }
        }
        return res;
    }
};