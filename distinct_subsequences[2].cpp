class Solution {
public:
    int numDistinct(string S, string T) {
        int m = T.length();
        int n = S.length();
        if (m > n) return 0;    // impossible for subsequence
    
        vector<int> path(m+1, 0);
        path[0] = 1;            // initial condition
    
        for (int j = 1; j <= n; j++) {
            // traversing backwards so we are using path[i-1] from last time step
            for (int i = min(m,j); i >= 1; i--) {  
                path[i] = path[i] + (T[i-1] == S[j-1] ? path[i-1] : 0);
            }
        }
    
        return path[m];
    }

};