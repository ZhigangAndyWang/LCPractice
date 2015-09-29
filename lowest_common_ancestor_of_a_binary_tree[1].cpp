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
        
    bool isAce(TreeNode* node,TreeNode*p,unordered_map<TreeNode*,int> &aces){
        if (!node) return false;
        if( aces[node] == -1 ) return false;
        if( aces[node] == 1 ) return true;
        if (node == p) {
            aces[node] = 1;
            return true;
        }
        if(isAce(node->left,p,aces) || isAce(node->right,p,aces)){
            aces[node] = 1;
            return true;
        }
        else{
            aces[node] = -1;
        }
        return false;
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        unordered_map<TreeNode*,int> p_aces;
        unordered_map<TreeNode*,int> q_aces;
        TreeNode *lca = root;
        while(lca){
            if (isAce(lca->left,p,p_aces) && isAce(lca->left,q,q_aces)){
                lca = lca->left;
                continue;
            }
            else if (isAce(lca->right,p,p_aces) && isAce(lca->right,q,q_aces) ){
                lca = lca->right;
                continue;
            }
            else{
                return lca;
            }
        }
        return lca;
    }
};