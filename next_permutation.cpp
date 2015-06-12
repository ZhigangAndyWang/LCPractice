class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        
        int n = nums.size();
        if(n==0 || n==1) return;
        
        int i = 0;
        for(i = n-2; i >= 0 ; --i){
            if(nums[i] < nums[i+1]) break;
        }
        
        if(i == -1){
            sort(nums.begin(),nums.end());
            return;
        }
        
        //find the digit which is closley larger than nums[i]
        int j = 0;
        int minDiff = INT_MAX;
        for(int k = i+1; k<n; ++k){
            if(nums[k] > nums[i]){
                int diff = nums[k] - nums[i];
                if(diff < minDiff){
                    minDiff = diff;
                    j = k;
                }
            }
        }
        
 
        int tmp = nums[j];
        nums[j] = nums[i];
        nums[i] = tmp;
        sort(nums.begin()+i+1, nums.end());
        return;

    }
};