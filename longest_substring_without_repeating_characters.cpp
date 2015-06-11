class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i = 0;
        int j = 0;
        int maxl = 0;
        if(s.size()==0 || s.size()==1) return s.size();
        
        map<char,bool> charOccured;
        charOccured[s[0]] = true;
        
        while(i<s.size() && j+1<s.size()){
            if( charOccured[s[j+1]] == false){
                charOccured[s[j+1]] = true;
                maxl = max(maxl,j+1-i+1);
                j++;
            }
            else if( charOccured[s[j+1]] == true){
                charOccured[s[i]] = false;
                maxl = max(maxl,j-i+1);
                i++;
            }
        }
        
        return maxl;
        
        
    }
};