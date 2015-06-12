class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int res;
        int minDiff = INT_MAX;
        
        int i,j,k;
        int n = nums.size();
        
        if (n < 3 ) return -1;
        
        sort(nums.begin(),nums.end());
        
        for(i=0;i<n-2;i++){
            if(i>0 && nums[i] == nums[i-1]) continue;
            k = n-1;
            j = i+1; 
            while (j != k ){
                int diff = nums[i] + nums[j] + nums[k] - target;
                if( abs(diff) < minDiff){
                    minDiff = abs(diff);
                    res = nums[i] + nums[j] + nums[k];
                }
                if(diff == 0){
                    return res;
                }
                else if( diff > 0){
                    k--;
                }
                else if( diff < 0){
                    j++;
                }
            }
        }
        return res;
    }
};