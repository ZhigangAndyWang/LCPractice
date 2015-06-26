class Solution {
public:
    int singleNumber(vector<int>& nums) {
        vector<int> bit(32,0);
        for(int num : nums){
            for(int i = 0; i < 32; i++){
                if(num & (1<<i)){
                    bit[i] = (bit[i]+1)%3;
                }
            }
        }
        int res = 0;
        for(int i = 0; i < 32; i++){
            res += (bit[i]<<i);
        }
        return res;
    }
};