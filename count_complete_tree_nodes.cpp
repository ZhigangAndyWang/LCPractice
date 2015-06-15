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
    bool getNode(TreeNode* root, int path, int depth){
        while (--depth && root){
            if( path & (1<<depth-1)){
                root = root->right;
            }
            else{
                root = root->left;
            }
        }
        return (root!=NULL);
    }
    
public:
    int countNodes(TreeNode* root) {
        //binary search the last level
        
        //get depth
        int depth = 0;
        TreeNode *node = root;
        while(node){
            node = node->left;
            depth++;
        }
        if (!depth) return 0;
        
        int left = 0; 
        int right = ( 1 << (depth-1) ) - 1;
        while(left<=right){
            int mid = (left+right)>>1;
            if ( getNode(root,mid,depth) ){
                left = mid + 1;
            }
            else{
                right = mid - 1;
            }
        }
        return (1<<depth-1)+right;
    }
    
};