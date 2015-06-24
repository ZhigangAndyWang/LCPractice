class Solution {
private:
    bool dfs(vector<vector<int> > &graph,vector<int> &visited, int i){
        if(visited[i] == -1) return false;
         if(visited[i] == 1) return true;   //important
        visited[i] = -1; //-1 means in processing
        for (int a : graph[i]){
            if (!dfs(graph,visited,a)) return false;
        }
        visited[i] = 1;
        return true;
    }
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<vector<int> > graph(numCourses,vector<int>(0));
        vector<int> visited(numCourses,0);
        for (pair<int,int> a: prerequisites){
            graph[a.second].push_back(a.first);
        }
        bool start = true;
        for(int i = 0; i < numCourses; ++i){
            if(!dfs(graph, visited, i)) return false;
        }
        return true;
        
    }
};