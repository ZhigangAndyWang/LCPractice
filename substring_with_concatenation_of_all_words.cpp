class Solution {
public:
    bool checkSubstrings(string sub, unordered_map<string,int> &wordCount, int wordLen, int numOfWords){
        unordered_map<string,int> wordFound;
        for(int i = 0; i < numOfWords; i++){
            string temp = sub.substr(i*wordLen,wordLen);
            if(wordCount.find(temp) == wordCount.end()) return false;
            wordFound[temp]++;
            if(wordFound[temp] > wordCount[temp]) return false;
        }
        // for(auto it = wordFound.begin(); it!=wordFound.end(); it++){
        //     if(wordFound[it->first]!=wordCount[it->first]) return false;
        // }
        return true;
    }
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> res;
        int wordLen = words[0].size();
        int totalLen = wordLen*words.size();
        
        if(s.size() < totalLen) return res;
        
        unordered_map<string,int> wordCount;
        for(string w: words){
            wordCount[w]++;
        }
        
        for(int i = 0; i < s.size()-totalLen+1 ; i++){
            string temp = s.substr(i,totalLen);
            bool checked = checkSubstrings(temp,wordCount,wordLen,words.size());
            if(checked) res.push_back(i); 
        }
        return res;
    }
};