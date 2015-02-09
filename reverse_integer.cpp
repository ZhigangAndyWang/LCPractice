#include <iostream>
using namespace std;

class Solution {
public:
    int reverse(int x) {
        if (x==0) return 0;
        int i = 0;
        int tmp = x;
        int res = 0;
        while(tmp != 0){
            int d = tmp%10;
            res = res*10 + d;
            tmp = tmp/10;
        }
        return res;
    }
};

int main(){
    Solution s;
    cout << s.reverse(1);
    cout <<endl;
}
