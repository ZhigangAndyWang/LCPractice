#include <cmath>
class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        int size = digits.size();
        if(digits.empty()) return digits;
        
        for(int i=size-1;i>=0;i--)
        {
            int t = digits[i];
            if(t!=9)
            {
                digits[i]++;
                return digits;
            }
            digits[i] = 0;
        }
        
        digits.insert(digits.begin(),1);
        return digits;
        
    }
};