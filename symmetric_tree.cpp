/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    bool areSymmetric(TreeNode *a,TreeNode *b){
        if(!a && !b) return true;
        if(!a || !b) return false;
        return (areSymmetric(a->left,b->right) && areSymmetric(a->right,b->left) && a->val==b->val);
    }    
public:
    bool isSymmetric(TreeNode *root) {
        if(root==NULL) return true;
        return areSymmetric(root->left,root->right);
    }
    

};