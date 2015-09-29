class Solution {
public:
    void reverseWords(string &s) {
        if(s.size()==0) return;
        for(int i = 0; i < s.size()-1-i; i++){
            swap(s[i],s[s.size()-1-i]);
        }
        s += " ";
        
        int ws = 0, we = 0;
        bool inWord = false;
        
        for(int i = 0; i < s.size(); i++){
            //leading space
            if(s[0] == ' ') {
                s = s.substr(1);
                i--;
                continue;
            }
            if(s[i] == ' ' && s[i-1] ==' ') {
                s = s.substr(0,i) + s.substr(i+1);
                i--;
                continue;
            }
            //end
            if( (s[i] == ' '|| i==s.size()-1) && inWord){
                inWord = false;
                we = i;
                for(int j = 0; ws+j < we-1-j; j++){
                    swap(s[ws+j],s[we-1-j]);
                }
            }
            //start
            if(s[i]!=' ' && (i == 0 ||s[i-1] == ' ')){
                inWord = true;
                ws = i;
            }
        }
        
        //trailing zeros
        while(s[s.size()-1] == ' '){
            s = s.substr(0,s.size()-1);
        }
    }
};