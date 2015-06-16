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
private:
    vector<TreeNode*> dfs(int start, int end){
        vector<TreeNode *> subTree; 
        if(start>end){
            subTree.push_back(NULL);  
            return subTree;  
        }
        
        for(int i=start; i <= end;i++){
            vector<TreeNode *> leftTree = dfs(start, i-1);
            vector<TreeNode *> rightTree = dfs(i+1, end);
            for ( TreeNode *l : leftTree ){
                for ( TreeNode *r : rightTree ){
                    TreeNode *node = new TreeNode(i);
                    node->left = l;
                    node->right = r;
                    subTree.push_back(node);
                }
            }
        }
        
        return subTree;
        
    }
public:
    vector<TreeNode*> generateTrees(int n) {
        if(n==0) return dfs(1,0);
        return dfs(1,n);
    }
};