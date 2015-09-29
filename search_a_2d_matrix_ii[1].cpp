class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        if(!m) return false;
        int n = matrix[0].size();
        if(!n) return false;
        
        return searchMatrixDaq(matrix,0,m-1,0,n-1,target);
    }
    bool searchMatrixDaq(vector<vector<int>>& matrix,  int is, int ie, int js, int je, int& target){
        int im = (is+ie)/2;
        int jm = (js+je)/2;
        if(is > ie || js > je) return false;
        
        if(is == ie && js == je){
            return matrix[is][js] == target;
        }
        
        if(matrix[im][jm] == target) return true;
        if(matrix[im][jm] > target){ //the right lower part of im,ie cannot contain target
            if(searchMatrixDaq(matrix,is,im-1,js,jm-1,target)) return true;
            if(searchMatrixDaq(matrix,im,ie,js,jm-1,target)) return true;
            if(searchMatrixDaq(matrix,is,im-1,jm,je,target)) return true;
            return false;
        }
        if(matrix[im][jm] < target){ //the left upper part of im,ie cannot contain target
            if(searchMatrixDaq(matrix,im+1,ie,jm+1,je,target)) return true;
            if(searchMatrixDaq(matrix,is,im,jm+1,je,target)) return true;
            if(searchMatrixDaq(matrix,im+1,ie,js,jm,target)) return true;
            return false;
        }
    }
};