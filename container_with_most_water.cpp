class Solution {
    // Reference : https://oj.leetcode.com/discuss/11482/yet-another-way-to-see-what-happens-in-the-o-n-algorithm
public:
    int maxArea(vector<int> &height) {
        int left = 0,right = height.size()-1;
        int max = 0;
        
        while(left!=right)
        {
            max = std::max(max,(right-left)*std::min(height[left],height[right]));
            if(height[left]-height[right]>0) right--;
            else left++;
        }
        
        return max;
    }
};