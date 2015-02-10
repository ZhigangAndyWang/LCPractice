#include <iostream>
#include <ctype.h>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        if(s.length()<=1) return true;

        int i = 0;
        int j = s.length()-1;
        
        char *a = &s[i];
        char *b = &s[j];
        
        while(i<j)
        {
            cout << "i="<<i<<" j="<<j<<endl;
            if(!isalpha(*a)) { a++; i++; continue;}
            if(!isalpha(*b)) { b--; j--; continue;}
            if(!isequal(*a,*b)) { return false; }
            a++;i++;b--;j--;
        }
        return true;
    }
    
    bool isValidChar(char c){
        if(isalpha(c)) return true;
        if(isdigit(c)) return true;
        return false;
    }
    
    bool isequal(char a,char b){
        a = (isalpha(a)? tolower(a):a);
        b = (isalpha(b)? tolower(b):b);
        return a==b;
    }
};
int main(){
    Solution s;
    cout << s.isPalindrome("1a2");
    return 0;
}
