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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        queue<TreeNode*> tq;
        vector<vector<int>> res;
        if(!root) return res;
        
        tq.push(root);
        bool beReversed = false;
        
        while(!tq.empty()){
            int n = tq.size();
            vector<int> sol;
            for(int i=0; i<n; ++i){
                TreeNode *node = tq.front();
                tq.pop();
                if ( node->left ) tq.push(node->left);
                if ( node->right ) tq.push(node->right);
                
                sol.push_back(node->val);
            }
            if ( beReversed == false ){
                beReversed = true;
            }
            else{
                std::reverse(sol.begin(),sol.end());
                beReversed = false;
            }
            
            res.push_back(sol);
        }
        return res;
    }
};