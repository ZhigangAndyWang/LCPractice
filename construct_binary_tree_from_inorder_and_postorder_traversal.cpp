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
    TreeNode* build(vector<int>& inorder, vector<int>& postorder, int i_s, int i_e, int p_s, int p_e){
        if (i_s >= i_e){
            return NULL;
        }
        //divide inorder into 2 sets
        int rootPos = find(inorder.begin()+i_s, inorder.begin()+i_e, postorder[p_e-1]) - inorder.begin();
        TreeNode *root = new TreeNode(postorder[p_e-1]);
        
        root->left = build(inorder,postorder, i_s,rootPos,p_s,p_s+rootPos-i_s);
        root->right = build(inorder,postorder, rootPos+1,i_e, p_s+rootPos-i_s,p_e-1);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if (!inorder.size() ) return NULL;
        
        TreeNode* root = build(inorder,postorder,0,inorder.size(),0,postorder.size());
        
        return root;
    }
};