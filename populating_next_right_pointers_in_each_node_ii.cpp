class Solution {
public:
    void connect(TreeLinkNode *root) {
        if(!root) return;
        queue<TreeLinkNode*> q;
        q.push(root);
        TreeLinkNode *n;
        while(!q.empty()){
            int l = q.size();
            for(int i=0;i<l;i++){
                n = q.front();
                q.pop();
                if(i!=l-1) n->next = q.front();
                if(n->left) q.push(n->left);
                if(n->right) q.push(n->right);
            } 
        }
        return;
    }
};