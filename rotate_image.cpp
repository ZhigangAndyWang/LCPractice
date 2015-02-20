class Solution {
public:
    void rotate(vector<vector<int> > &matrix) {
        if(matrix.size()==0) return;
        
        int n = matrix.size();
        int i=0,j=n-1;
        
        for(;j>i;i++,j--)
        {
            for(int k=i;k<j;k++)
            {
                int temp = matrix[i][k];
                matrix[i][k] = matrix[n-1-k][i];
                matrix[n-1-k][i] = matrix[n-1-i][n-1-k];
                matrix[n-1-i][n-1-k] = matrix[k][n-1-i];
                matrix[k][n-1-i] = temp;
            }
        }
    }
};