class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,int> findMap; //the value indicates the latest index for an element with the value "key"
        
        for(int i=0; i<nums.size(); i++){
            auto it = findMap.find(nums[i]);
            
            if(it == findMap.end()){
                findMap[nums[i]] = i;
                continue;
            }
            else{   //found
                int prevIndex = it->second;
                if( i-prevIndex > k){
                    findMap[nums[i]] = i; //update index
                }
                else{
                    return true;
                }
            }
        }
        return false;
    }
};