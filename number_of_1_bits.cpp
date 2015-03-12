class Solution {
public:
    int hammingWeight(uint32_t n) {
        int res;
        for(int i=0;i<32;i++)
        {
            if(n==0) break;
            if(n&1) res+=1;
            n = n>>1;
        }
        return res;
    }
};