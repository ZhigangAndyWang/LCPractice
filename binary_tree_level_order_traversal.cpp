/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 #include <queue>
class Solution {
public:
    vector<vector<int> > levelOrder(TreeNode *root) {
        queue<TreeNode*> tq;
        vector<vector<int>> res;
        if(!root) return res;
        tq.push(root);
        
        
        while(!tq.empty())
        {
            int n=tq.size();
            vector<int> tempVec;
            
            for(int i=0;i<n;i++)
            {
                TreeNode* it = tq.front();
                if(it->left)
                {
                    tq.push(it->left);
                }
                if(it->right)
                {
                    tq.push(it->right);
                }
                tempVec.push_back(it->val);
                tq.pop();
            }
            res.push_back(tempVec);
        }
        return res;
    }
};