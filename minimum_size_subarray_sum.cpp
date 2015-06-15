class Solution {
public:
    int minSubArrayLen(int s, vector<int> &nums) {
        if(nums.size() == 0) return 0;
        
        int res1 = 0;
        int res2 = 0;
        int res = 0;
        
        int tail = nums.back();
        int res2Sum = 0;
        for(int i=nums.size()-1;i>=0;i--){
            res2Sum += nums[i];
            res2 ++;
            if(res2Sum >= s) break;
            if(res2Sum < s && i == 0) return 0;
        }
        
        nums.pop_back();
        res1 = minSubArrayLen(s, nums);
        nums.push_back(tail);
        
        if(res1 && res2)
            res = min(res1,res2);
        else if(!res1 && !res2)
            res = 0;
        else if(!res1 && res2)
            res = res2;
        else if(!res2 && res1)
            res = res1;
        return res;
    }
};