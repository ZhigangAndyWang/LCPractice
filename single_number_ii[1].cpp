class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int one = 0, two = 0;
        int three;
        for(int num : nums){
            two |= one & num;
            one ^= num;
            //if one contains 1 and two contains 1, set both of them to 0
            three = ~(one & two);
            one &= three;
            two &= three;
        }
        return one;
    }
};

/*