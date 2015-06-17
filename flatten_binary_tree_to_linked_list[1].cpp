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
public:
    void flatten(TreeNode* root) {
        if (!root) return;
        if (!root->left && !root->right) return;
        while(root){
            if (root->left){
                //get the left->right->right->...->right most child
                TreeNode *rightMost = root->left;
                while(rightMost->right){
                    rightMost = rightMost->right;
                }
                //append right child to left's right most child
                rightMost->right = root->right;
                //move left to right
                root->right = root->left;
                root->left = NULL;
            }
            //next iteration
            root = root->right;

        }
    }
};