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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        if(!root) return res;
        
        stack<TreeNode*> st;
        TreeNode *pre = NULL;
        st.push(root);
        
        while(!st.empty()){
            TreeNode *node = st.top();
            if ((!node->left && !node->right) || (pre!=NULL && (node->left == pre || node->right == pre)) ){
                res.push_back(node->val);
                st.pop();
                pre = node;
            }
            else{
                if(node->right) st.push(node->right);
                if(node->left) st.push(node->left);
            }
        }
        return res;
    }
};