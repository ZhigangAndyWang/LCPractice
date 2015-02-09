#include <iostream>
#include <math.h>
using namespace std;


class Solution {
    public:
        int titleToNumber(string s) {
            int l = s.length();
            int res = 0;
            if (l==0) return 0;

            for (int i=0; i < l; i++){
                char c = s.at(i);
                int t = c-'A'+1;
                res += pow(26,l-1-i)*t; 
            }
            return res;
        }
};

int main(){
    Solution s;
    cout << s.titleToNumber("AA");
    return 0;
}

