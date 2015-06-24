class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<vector<int> > graph(numCourses,vector<int>(0));
        vector<int> in(numCourses,0);
        
        for(pair<int,int> a : prerequisites){
            graph[a.second].push_back(a.first);
            in[a.first]++;
        }
        
        queue<int> q;
        for(int i = 0 ; i < in.size() ; ++i){
            if(in[i]==0){
                q.push(i);
            }
        }
        
        while(!q.empty()){
            int k = q.front();
            q.pop();
            for(int i = 0; i < graph[k].size(); ++i){
                in[graph[k][i]]--;
                if(in[graph[k][i]] == 0){
                    q.push(graph[k][i]);
                }
            }
        }
        
        for(int i = 0 ; i < in.size() ; ++i){
            if(in[i]!=0){
                return false;
            }
        }
        
        return true;

    }
};