#include <iostream>
using namespace std;

class Solution {
public:
    int singleNumber(int A[], int n) {
        int res = 0;
        for(int i=0;i<n;i++){
            res ^= A[i];
        }
        return res;
    }
};

int main(){
    Solution s;
    int A[] = {2,2,1,-1,1};
    cout << s.singleNumber(A,5);
    cout <<endl;
}
