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
    void dfs(TreeNode *node,int &cur, int &sum)
    {
        int temp = cur*10 + node->val;
        if(!node->left&&!node->right)
        {
            sum += temp;
        }
        if(node->left) dfs(node->left,temp,sum);
        if(node->right) dfs(node->right,temp,sum);
    }
public:
    int sumNumbers(TreeNode *root) {
        int cur=0,sum=0;
        if(!root) return sum;
        dfs(root,cur,sum);
        return sum;
    }
};