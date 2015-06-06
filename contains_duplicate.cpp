class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> findSet;
        for(int i=0; i < nums.size(); i++){
            if(findSet.find(nums[i]) != findSet.end()){
                return true;
            }
            findSet.insert(nums[i]);
        }
        return false;
    }
};