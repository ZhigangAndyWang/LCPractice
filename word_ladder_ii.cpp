class Solution {
private:
    vector<string> findNeighbors(string s, unordered_set<string> &dict){
        vector<string> res;
        for(int i =0; i<s.size(); i++){
            char c = s[i];
            for(int j = 0; j<26; j++){
                char r = 'a' + j;
                if(c == r) continue;
                s[i] = r;
                if(dict.count(s)!=0){
                    res.push_back(s);
                }
            }
            s[i] = c;
        }
        return res;
    }
    
public:
    vector<vector<string>> findLadders(string start, string end, unordered_set<string>& dict) {
        dict.insert(end);
        vector<vector<string>> res;
        int minLen = -1;

        queue< pair<string,vector<string>> > sq;
        
        sq.push(make_pair(start,vector<string>(1,start)));
        
        unordered_set<string> visited;
        
        while(!sq.empty()){
            pair<string,vector<string>> p = sq.front();
            sq.pop();
            
            if(minLen > 0 && p.second.size() > minLen) continue;
            
            if(p.first == end) {
                if(minLen == -1) minLen = p.second.size();
                res.push_back(p.second);
                // return res;
            }
            
            vector<string> nbs = findNeighbors(p.first,dict);
            for(string w : nbs){
                if(visited.count(w) != 0) continue;
                vector<string> path = p.second;
                path.push_back(w);
                sq.push(make_pair(w,path));
            visited.insert(w);
            }
        }
        return res;
    }
};