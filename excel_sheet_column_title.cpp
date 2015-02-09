#include <iostream>
using namespace std;

class Solution {
    public:
        string convertToTitle(int n) {
            string res = "";
            int d = 0;
            while(n>0){
                n--;
                int cur = n%26;
                char last_c = 'A'+cur;
                res.insert(0,1,last_c);
                n /= 26;
            }
            return res;
        }
};

int main(){
    Solution s;
    cout << s.convertToTitle(27);
    return 0;
}

