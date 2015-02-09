#include <iostream>
using namespace std;

class Solution {
    public:
        int removeElement(int A[], int n, int elem) {
            int j=0;
            for (int i=0;i<n;){
                A[i] = A[j];
                if (A[i] == elem) {
                    n--;
                    A[i] = A[j+1];
                }
                else{
                    i++;
                }
                j++;
            }
            return n;
        }
};

int main(){
    Solution s;
    int a[] = {3,3,2,1};
    cout<< s.removeElement(a,4,3);
    return 0;
}
