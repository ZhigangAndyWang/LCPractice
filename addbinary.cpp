#include <iostream>
using namespace std;

class Solution {
    public:
        string addBinary(string a, string b) {
            if(b.length()>a.length())
                a.insert(0,b.length()-a.length(),'0');
            else
                b.insert(0,a.length()-b.length(),'0');
            int l = a.length();
            int cumulated = 0;
            string c ="";
            for (int i=0;i<l;i++){
                int sum = (a[l-1-i]-'0') + (b[l-1-i]-'0') + cumulated;
                char last = (sum%2)+'0';
                cumulated = sum/2;
                c.insert(0,1,last);
            }
            if (cumulated ==1) c.insert(0,1,'1');
            return c;
        }
};

int main(){
    Solution s;
    string c = s.addBinary("11","1");
    cout << c;
    return 0;
}

