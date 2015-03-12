class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        
        if(matrix[0][0]>target||matrix[m-1][n-1]<target) return false;
        if(matrix[0][0]==target) return true;
        int front = 0; int end = m*n-1;
        while(end-front>1)
        {
            int mid = (front+end)/2;
            int r = mid/n; int c = mid%n;
            if(target==matrix[r][c]) return true;
            if(matrix[r][c]>target) end=mid;
            else front = mid;
        }
        return matrix[front/n][front%n]==target||matrix[end/n][end%n]==target;

    }
};