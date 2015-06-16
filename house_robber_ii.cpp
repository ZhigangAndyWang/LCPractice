class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(nums.empty()) return 0;
        
        vector<int> dp(n+1,0);
        vector<int> dpWithoutFirst(n+1,0);
        vector<int> dpNoCircle(n+1,0);
        
        dpWithoutFirst[1] = 0;
        dpNoCircle[1] = nums[0];
        
        for(int i=2; i<=n ; i++){
            dpWithoutFirst[i] = max( dpWithoutFirst[i-2]+nums[i-1] , dpWithoutFirst[i-1] );
            dpNoCircle[i] = max( dpNoCircle[i-2]+nums[i-1] , dpNoCircle[i-1] );
        }
        
        int res = max(dpWithoutFirst[n-2]+nums[n-1], dpNoCircle[n-1]);
        
        return res;
    }
};