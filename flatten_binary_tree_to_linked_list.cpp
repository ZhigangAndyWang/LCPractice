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
    void dfs(TreeNode *node){
        if(!node) return;
        TreeNode *lastNode1 = lastNode;
        lastNode = node;
        
        if( node->left ) {
            dfs(node->left);
        }
        if( node->right ) {
            dfs(node->right);
        }
        if ( lastNode1 && lastNode1->left != node) {
            lastNode1->left = node;
            lastNode1->right = NULL;
        }
    }
    
    void switchToRight(TreeNode *node){
        if (!node) return;
        node->right = node->left;
        node->left = NULL;
        switchToRight(node->right);
    }
    
public:
    TreeNode *lastNode;
    void flatten(TreeNode* root) {
        if(!root) return;
        dfs(root);  //append all right child to last node's left according to preorder traversal
        switchToRight(root);
    }
};