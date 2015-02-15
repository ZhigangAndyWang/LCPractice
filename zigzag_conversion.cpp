#include <iostream>
using namespace std;

class Solution {
public:
    string convert(string s, int nRows) {
        if(s=="") return "";
        if(nRows==1) return s;
        int n = 2*nRows-2;
        string* res = new string[nRows];
        for(int i=0;i<s.length();i++)
        {
            int j = i%n;
            if(j<nRows) 
            {
                res[j]+=s[i];
            }
            else
            {
                res[n-j]+=s[i];
            }                     
        }
        string r="";
        for(int i=0;i<nRows;i++)
        {
            r+=res[i];
        }
        return r;
    }
};
int main(){
    Solution s;
    cout << s.convert("ABCDACANCASKCN",3);
    return 0;
}
