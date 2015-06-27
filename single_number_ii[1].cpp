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
            two |= A[i] & one              #two为1时，不管A[i]为什么，two都为1
            one = A[i] ^ one               #异或操作，都是1就进位
            three = ~(one & two)　　　　    #以下三步的意思是：如果one和two都为1时，就清0，反之则保持原来状态。
            one &= three
            two &= three
*/