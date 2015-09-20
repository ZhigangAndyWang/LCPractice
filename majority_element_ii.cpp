class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        //Boyer-Moore majority vote algorithm
        int candidate1, candidate2;
        int ct1 = 0 , ct2 = 0;
        vector<int> res;
        
        if(nums.size() <=1 ) return nums;
        
        for(int num: nums){
            if(num==candidate1){
                ct1++;
            } 
            else if (num == candidate2){
                ct2++;
            }
            else if (ct1 == 0){
                candidate1 = num;
                ct1++;
            }
            else if (ct2 == 0){
                candidate2 = num;
                ct2++;
            }
            else{
                ct1--;
                ct2--;
            }
        }
        ct1 = 0;
        ct2 = 0;
        for(int num:nums){
            if(num == candidate1) ct1++;
            if(num == candidate2) ct2++;
        }
        if(ct1 > nums.size()/3) res.push_back(candidate1);
        if(ct2 > nums.size()/3) res.push_back(candidate2);
        return res;
    }
};