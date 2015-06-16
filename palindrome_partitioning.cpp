class Solution {
private:
    bool isPalindrome(string s, int begin, int end){
        if(s.empty() || s.size() == 1 ) return true;
        while(begin < end){
            if(s[begin++]!=s[end--]) return false;
        }
        return true;
    }
    
    void backtracking(vector<vector<string>> &res, int pos, vector<string> &sol, string s){
        if (pos == s.size()){
            res.push_back(sol);
        }
        
        for(int i=pos; i<s.size();i++){
            if (isPalindrome(s,pos,i)){
                sol.push_back(s.substr(pos,i-pos+1));
                backtracking(res,i+1,sol,s);
                sol.pop_back();
            }
        }
    }
    
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string > sol;
        
        backtracking(res,0,sol,s);
        return res;
    }
};