class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        
        int m = matrix.size();
        if (m == 0) return res;
        
        int n = matrix[0].size();
        if (n == 0) return res;
        
        
        if (m == 1) return matrix[0];
        if (n == 1){
            for(int i=0; i < m ;++i){
                res.push_back(matrix[i][0]);
            }
            return res;
        } 
        
        res.insert(res.end(),matrix[0].begin(),matrix[0].end());
        for(int i = 1; i < m-1 ; i++) res.push_back(matrix[i][n-1]);
        for(int j = n-1; j >= 0 ; j--) res.push_back(matrix[m-1][j]);
        for(int i = m-2; i > 0 ; i--) res.push_back(matrix[i][0]);
                
                
        for(int i=1;i<=m-2;++i){
            matrix[i].erase(matrix[i].begin());
            matrix[i].pop_back();
        }
        matrix.erase(matrix.begin());
        matrix.erase(matrix.end()-1); //pop_back

        vector<int > next= spiralOrder(matrix);
        
        res.insert(res.end(),next.begin(),next.end());
        return res;
    }
};