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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        if(!root) return res;
        
        queue<TreeNode*> tq;
        tq.push(root);
        while(!tq.empty()){
            int n = tq.size();
            for(int i=0; i<n;i++){
                TreeNode *node = tq.front();
                if(i==n-1) res.push_back(node->val);
                tq.pop();
                if(node->left) tq.push(node->left);
                if(node->right) tq.push(node->right);
            }
        }
        
        return res;
    }
};