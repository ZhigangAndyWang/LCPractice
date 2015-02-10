#include <cmath>
class Solution {
public:
    int trailingZeroes(int n) {
        if(n<5) return 0;
        int count = 0; //the same as number of five
        for(int depth=1;pow(5,depth)<=n;depth++){
            count += n/pow(5,depth);
        }
        return count;
    }
};