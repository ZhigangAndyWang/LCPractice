class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        if(!nums.size() ) return 0;
        int begin = 0;
        int end = 0;
        int minLen = INT_MAX;
        int curSum = 0;
        
        for(begin = 0; begin<nums.size(); begin++){
            for( ; curSum < s && end < nums.size() ;end++){
                curSum += nums[end];
            }
            
            if(curSum >= s)
                minLen = min(minLen, end-begin);
        
            curSum -= nums[begin];
        }
        if(minLen == INT_MAX) return 0;
        return minLen;
    }
};