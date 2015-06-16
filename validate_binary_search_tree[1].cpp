/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private: 
    bool isValid(TreeNode *root, bool left,bool right, int lower,int upper){
        if(!root) return true;
        int v = root->val;
        if ( v >= upper && left ) return false;
        if ( v <= lower && right) return false;
        return isValid(root->left,true,right,lower,v) && isValid(root->right,left,true,v,upper);
    }
public:
    bool isValidBST(TreeNode* root) {
        if (!root) return true;
        if (!root->left && !root->right ) return true;
        int lastV = root->val;
        return isValid(root,false,false,INT_MIN,INT_MAX);
    }
};