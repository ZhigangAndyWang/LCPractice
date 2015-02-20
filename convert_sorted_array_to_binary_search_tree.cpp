/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
TreeNode *dfs(vector<int> &num,int start,int end);
class Solution {
public:
    TreeNode *sortedArrayToBST(vector<int> &num) 
    {
        if(num.size()==0) return NULL;
        
        return dfs(num,0,num.size()-1);
    }
    
    TreeNode *dfs(vector<int> &num,int start,int end)
    {
        int mid = start + (end-start)/2;
        
        TreeNode *node = new TreeNode(num[mid]);
        if(start==end) return node;
        
        if(start<=mid-1)
            node->left = dfs(num,start,mid-1);
        if(mid+1<=end)
            node->right = dfs(num,mid+1,end);
        return node;
    }
};