/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 #include <stack>
class Solution {
public:
    vector<vector<int> > levelOrderBottom(TreeNode *root) {
        queue<TreeNode*> tq;
        vector<vector<int>> res;
        if(!root) return res;
        
        tq.push(root);
        while(!tq.empty())
        {
            int n = tq.size();
            vector<int> temp;
            temp.clear();
            for(int i=0;i<n;i++)
            {
                TreeNode *t = tq.front();
                tq.pop();
                if(t->left) tq.push(t->left);
                if(t->right) tq.push(t->right);
                temp.push_back(t->val);
            }
            res.push_back(temp);
        }
        
        std::reverse(res.begin(),res.end());
        
        return res;
    }
};