class Solution {
private:
    void backtracking(vector<string> &res,int curpos,vector<int> &sp,string s, unordered_set<string>& wordDict,
            vector<vector<bool> > mp){
        if(curpos == s.size()){
            string str = s;
            for(int i=0;i<sp.size()-1;i++){
                str.insert(sp[i]+i+1," ");
            }
            res.push_back(str);
            return;
        }
        
        for(int i=curpos;i<s.size();i++){
            if(mp[curpos][i]==true){
                sp.push_back(i);
                backtracking(res,i+1,sp,s,wordDict,mp);
                sp.pop_back();
            }
        }
        return;
    }
public:
    vector<string> wordBreak(string s, unordered_set<string>& wordDict) {
        int n = s.size();
        vector <string> res;
        
        if(!n) return res;
        
        vector<vector<bool> > mp(n,vector<bool>(n,false));
        
        for(int i=0;i < n; ++i){
            for(int j=i;j<n; ++j){
                if ( wordDict.find(s.substr(i,j-i+1) ) != wordDict.end() ){
                    mp[i][j] = true;
                }
            }
        }
        
        bool flag =false;
        for (int i=0;i<s.size();i++){
            if (mp[i][s.size()-1]){
                flag = true; break;
            }
        }
        if(!flag) return res;
        
        vector<int> sp; //substring positions
        backtracking(res,0,sp,s,wordDict,mp);
        return res;
    }
};