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
    bool isValid(TreeNode *root, long long lower,long long upper){
        if(!root) return true;
        int v = root->val;
        if ( v <= lower || v >= upper) return false;
        return isValid(root->left,lower,v) && isValid(root->right,v,upper);
    }
public:
    bool isValidBST(TreeNode* root) {
        if (!root) return true;
        if (!root->left && !root->right ) return true;
        int lastV = root->val;
        long long min = LLONG_MIN; //std::numeric_limits<long long>::min();
        long long max = LLONG_MAX; //std::numeric_limits<long long>::max();
        return isValid(root,min,max);
    }
};