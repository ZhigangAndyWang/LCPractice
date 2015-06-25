class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        //priority queue
        int n = nums.size();
        priority_queue<int, vector<int>, std::greater<int> > q; //min heap
        for (int a : nums){
            if(q.size() < k){
                q.push(a);
            }
            else{
                if(a > q.top()){
                    q.pop();
                    q.push(a);
                }
            }
        }
        return q.top();
    }
};