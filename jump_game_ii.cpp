class Solution {
public:
    int jump(vector<int>& nums) {
        int curMax = 0;
        int lastMax;
        int lastI;
        int njumps = 0;
        int i = 0;
        
        while(true){
            if(curMax >= nums.size()-1) break;
            
            lastMax = curMax;
            lastI = i;
            
            for( i = lastI ; i <= lastMax; i++){
                curMax = max(curMax, nums[i]+i);
            }
            if(curMax == lastMax) return -1;
            njumps++;
        }
        return njumps;
    }
};