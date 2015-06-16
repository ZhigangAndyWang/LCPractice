class Solution {
private:
    void backtracking(vector<string> &res, int pos, vector<int> &terminates, string s){
        if( pos == s.size() && terminates.size() == 4 ){
            string str = s;
            for(int i = 0; i<terminates.size()-1; i++){
                str.insert(terminates[i]+i,".");
            }
            res.push_back(str);
        }
        if ( pos > s.size() || (pos == s.size() && terminates.size()<4) || terminates.size() > 4) return;
        
        if (s[pos] == '0'){
            terminates.push_back(pos+1);
            backtracking(res,pos+1,terminates,s);
            terminates.pop_back();
        }
        else{
            int leftChars = s.size() - pos;
            for (int i = 0; i<min(3,leftChars); ++i){
                int num = 0;
                for(int j=0; j<i+1; ++j){
                    num = num*10 + s[pos+j]-'0';
                }
                if(num < (1<<8) ){
                    terminates.push_back(pos+i+1);
                    backtracking(res,pos+i+1,terminates,s);
                    terminates.pop_back();
                }
            }
        }
        return;
    }
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        vector<int> terminates;
        
        backtracking(res,0,terminates,s);
        return res;
    }
};