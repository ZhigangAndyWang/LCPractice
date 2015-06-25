class Solution {
private:
    int partition(vector<int> &nums, int l, int r){
        //choose most left as the pivot
        int pivot = nums[l];
        int storedIndex = l;
        for (int i = l+1; i <= r ; i++){
            if( nums[i] > pivot){
                storedIndex++;
                swap(nums[i],nums[storedIndex]);
            }
        }
        swap(nums[l],nums[storedIndex]);
        return storedIndex;
    }
    
public:
    int findKthLargest(vector<int>& nums, int k) {
        //quick sort algorithm solution
        int left = 0, right = nums.size()-1;
        while(left <= right){
            int pos = partition(nums,left,right);
            if (pos == k-1) {return nums[pos];}
            else if ( pos < k-1 ){
                left = pos+1;   //?
            }
            else if ( pos > k-1 ){
                right = pos-1;
            }
        }
    }
};