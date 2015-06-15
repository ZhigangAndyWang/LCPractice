class Solution {
public:
    bool search(vector<int>& nums, int target) {
        
        if(!nums.size()) return -1;
        
        int l = 0;
        int r = nums.size()-1;
        
        while(l<=r){
            int mid = l+(r-l)/2;
            // int mid = (l+r)/2;
            if(nums[mid] == target) return true;
            
            if(nums[mid] > nums[l]){
                if(nums[l] <= target && target < nums[mid]){
                    r = mid-1;
                }
                else{
                    l = mid+1;
                }
            }
            else if(nums[mid] < nums[l]){
                if(nums[mid] < target && target<= nums[r]){
                    l = mid+1;
                }
                else{
                    r = mid-1;
                } 
            }
            else if(nums[mid] == nums[l]){ //mid!=target, l!=target
                l++;
            }
        }
        return false;
    }
};