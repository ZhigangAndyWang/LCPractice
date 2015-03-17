/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int> > pathSum(TreeNode *root, int sum) 
    {
        vector<vector<int> > res;
        if(!root) return res;
        
        vector<int> curPath;
        int curSum = 0;
        dfs(curPath,curSum,res,root,sum);
        
        return res;
    }
    
    void dfs(vector<int> &curPath, int curSum, vector<vector<int> > &res, TreeNode *curNode, int sum)
    {
        if(curNode == NULL) return;
        curPath.push_back(curNode->val);
        if(curSum+curNode->val == sum && !curNode->left && !curNode->right)
        {
            res.push_back(curPath);
            curPath.pop_back();
            return;
        }
        if(curNode->left) dfs(curPath,curSum+curNode->val,res,curNode->left,sum);
        if(curNode->right) dfs(curPath,curSum+curNode->val,res,curNode->right,sum);
        curPath.pop_back();
    }
};