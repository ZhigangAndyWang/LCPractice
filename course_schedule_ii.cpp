class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<int> res;
        vector<vector<int> > graph(numCourses);
        vector<int> in(numCourses,0);
        
        for ( pair<int,int> a:prerequisites){
            graph[a.second].push_back(a.first);
            in[a.first]++;
        }
        
        queue<int> q;
        int count = 0;
        
        for(int i=0; i < numCourses; i++){
            if(in[i] == 0) {
                count++;
                q.push(i);
                res.push_back(i);
            }
        }
        
        while(!q.empty()){
            int k = q.front();
            q.pop();
            for(int i : graph[k]){
                in[i]--;
                if (in[i]==0){
                    count++;
                    q.push(i);
                    res.push_back(i);
                }
            }
        }
        
        if(count!=numCourses) return vector<int>(0);
        
        return res;
    }
};