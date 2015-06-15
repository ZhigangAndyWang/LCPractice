class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if(!nums.size()) return -1;
        int maxp = nums[0];
        int minp = nums[0];
        int res = nums[0];
        for(int i=1; i<nums.size(); ++i){
            int tmpmaxp = maxp;
            int tmpminp = minp;
            maxp = max( max(tmpmaxp*nums[i],tmpminp*nums[i]), nums[i]);
            minp = min( min(tmpminp*nums[i],tmpmaxp*nums[i]), nums[i]);
            res = max(res,maxp);
        }
        
        return res;
    }
};