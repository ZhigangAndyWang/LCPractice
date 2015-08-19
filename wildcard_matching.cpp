class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size();
        int n = p.size();
        
        int i = 0, j = 0;
        
        int starPos = -1;
        int matchedSPos = -1;
        
        while ( i<m ){
            if ( s[i] == p[j] || p[j] == '?'){
                i++;
                j++;
                // matchedSPos = i;
                continue;
            }
            //s[i]!=p[j]
            if (p[j] == '*'){
                matchedSPos = i;
                starPos = j++;
                continue;
            }
            if ( starPos != -1){
                j = starPos+1;
                matchedSPos ++;
                i = matchedSPos;
                continue;
            }
            else 
                return false;
        }
        
        while(p[j] == '*') j++;
        
        return j==n;
        
    }
};