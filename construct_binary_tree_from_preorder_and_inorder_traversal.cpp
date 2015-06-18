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
    TreeNode* build(TreeNode *root, vector<int>& preorder, vector<int>& inorder, int pre1, int pre2, int in1, int in2){
        if (pre1 >= pre2 || !root){
            return NULL;
        }
        //divide inorder into 2 sets
        int rootPos = find(inorder.begin()+in1, inorder.begin()+in2, root->val) - inorder.begin();
        TreeNode *left = NULL, *right = NULL;
        if (in1 < rootPos){
            left = new TreeNode(preorder[pre1+1]);
        }
        if (rootPos < in2-1){
            right = new TreeNode(preorder[pre1+1+rootPos-in1]);
        }
        root->left = build(left,preorder,inorder, pre1+1,pre1+1+rootPos-in1,in1,rootPos);
        root->right = build(right,preorder,inorder, pre1+1+rootPos-in1,pre2, rootPos+1,in2);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (!preorder.size() ) return NULL;
        
        TreeNode* root = new TreeNode(preorder[0]);
        build(root,preorder,inorder,0,preorder.size(),0,inorder.size());
        
        return root;
    }
};