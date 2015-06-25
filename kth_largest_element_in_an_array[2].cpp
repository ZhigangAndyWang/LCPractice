class Solution {
private:
    int heap_size;
public:
    inline int parent(int idx) {
        return (idx - 1) >> 1;
    }
    inline int left(int idx) {
        return (idx << 1) + 1;
    }
    inline int right(int idx) {
        return (idx << 1) + 2;
    }
    //main procedure for heapify, shall learn
    void max_heapify(vector<int>& nums, int idx) {
        int largest = idx;
        int l = left(idx), r = right(idx);
        if (l < heap_size && nums[l] > nums[largest]) largest = l;
        if (r < heap_size && nums[r] > nums[largest]) largest = r;
        if (largest != idx) {
            swap(nums[idx], nums[largest]);
            max_heapify(nums, largest);
        }
    }
    
    void build_max_heap(vector<int>& nums) {
        heap_size = nums.size();
        for (int i = (heap_size >> 1) - 1; i >= 0; i--)
            max_heapify(nums, i);
    }
    
    
    int findKthLargest(vector<int>& nums, int k) {
        build_max_heap(nums);
        for (int i = 0; i < k-1; i++) {
            swap(nums[0], nums[heap_size - 1]); // get rid of the ith max value, which is nums[0]
            heap_size--;
            max_heapify(nums, 0);
        }
        return nums[0]; 
    }
};