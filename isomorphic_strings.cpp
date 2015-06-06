class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.size()!=t.size()) return false;
        if(s.empty()) return true;
        
        unordered_map<char,char> matching1;
        unordered_map<char,char> matching2;
        //A to B
        for(int i = 0;i < s.size();i++){
            auto it = matching1.find(s[i]);
            auto it2 = matching2.find(t[i]);
            
            if(it!=matching1.end()){
                if(t[i] != it->second)
                    return false;
            }
            else{
                matching1[ s[i] ] = t[i];
            }
            
            if(it2!=matching2.end()){
                if(s[i] != it2->second)
                    return false;
            }
            else{
                matching2[ t[i] ] = s[i];
            }
        }
        
        return true;
        
    }
};