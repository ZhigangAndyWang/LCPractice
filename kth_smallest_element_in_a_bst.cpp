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
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> st;
        TreeNode *node = root;
        
        while(node){
            st.push(node);
            node = node->left;
        }
        
        int x = 0;
        while(!st.empty()){
            x++;
            node = st.top();
            st.pop();
            if(x == k) return node->val;
            
            TreeNode *right = node->right;
            while(right){
                st.push(right);
                right = right->left;
            }
        }
    }
};