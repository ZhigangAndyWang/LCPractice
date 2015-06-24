/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
private:
    UndirectedGraphNode *dfs(UndirectedGraphNode *node, unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> &visited) {
        UndirectedGraphNode *nodeCopy = new UndirectedGraphNode(node->label);
        visited[node] = nodeCopy;
        
        vector<UndirectedGraphNode *> nbs = node->neighbors;
        for(UndirectedGraphNode* nb : nbs){
            if(visited.find(nb) == visited.end()){
                //new node
                nodeCopy->neighbors.push_back(dfs(nb,visited));
            }
            else{
                nodeCopy->neighbors.push_back(visited[nb]);
            }
        }
        
        return nodeCopy;
    }
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if(node == NULL) return NULL;
        unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> visited;
        UndirectedGraphNode *res = dfs(node,visited);
        return res;
    }
};