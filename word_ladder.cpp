class Solution {
private:
    vector<string> findNeighbors(string s, unordered_set<string> &wordDict){
        vector<string> res;
        for(int i =0; i<s.size(); i++){
            char c = s[i];
            for(int j = 0; j<26; j++){
                char r = 'a' + j;
                if(c == r) continue;
                s[i] = r;
                if(wordDict.count(s)!=0){
                    res.push_back(s);
                }
            }
            s[i] = c;
        }
        return res;
    }
    
public:
    int ladderLength(string beginWord, string endWord, unordered_set<string>& wordDict) {
        wordDict.insert(endWord);

        queue<pair<string,int>> sq;
        unordered_set<string> visited;
        
        sq.push(make_pair(beginWord,0));
        visited.insert(beginWord);
        
        while(!sq.empty()){
            pair<string,int> p = sq.front();
            sq.pop();
            
            if(p.first == endWord) return p.second+1;
            
            vector<string> nbs = findNeighbors(p.first,wordDict);
            for(string w : nbs){
                if(visited.count(w) != 0) continue;
                sq.push(make_pair(w,p.second+1));
                visited.insert(w);
            }
        }
    }
};