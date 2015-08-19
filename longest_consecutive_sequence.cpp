class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> ht;
        for(int n : nums)
            ht.insert(n);
        
        int maxV = INT_MIN;
        
        for(int n : nums){
            if (ht.empty() ) break;
            int len = 0;
            int index = n;
            
            while(ht.find(index)!=ht.end()){
                ht.erase(index);
                len ++;
                index --;
            }
            
            index = n+1;
            
            while(ht.find(index)!=ht.end()){
                ht.erase(index);
                len ++;
                index ++;
            }
            
            maxV = max(len,maxV);
        }
        return maxV;
    }
};