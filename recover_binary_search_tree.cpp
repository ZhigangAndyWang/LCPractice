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

    TreeNode *first = NULL;
    TreeNode *second = NULL;
    TreeNode *prev = NULL;
    
    void dfs(TreeNode *root){
        if(!root) return;
        dfs(root->left);
        // if (!prev){
        //     prev = root;
        //     break;
        // }
        if (prev && prev->val > root->val){
            if(!first){
                first = prev;
                second = root;
            }
            else{
                second = root;
            }
        }
        prev = root;
        dfs(root->right);
    }
    void recoverTree(TreeNode* root) {
        //O(n) space solution
        if(!root) return;
        dfs(root);
        // std::swap(first,second); // DOESNOT work
        int tmp = first->val;
        first->val = second->val;
        second->val = tmp;

    }
};