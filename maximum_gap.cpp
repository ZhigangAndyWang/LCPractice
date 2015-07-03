class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int n = nums.size();
        if ( n<2 ) return 0;
        int b = INT_MIN,a = INT_MAX;
        for(int n : nums){
            b = max(b,n);
            a = min(a,n);
        }
        
        // if ( b-a <= 1) return b-a;
        
        double gap = (double)(b-a)/(n-1);
        vector<int> bkt_max(n,INT_MIN); // bkts[i] contains numbers from a+i*gap -> a+(i+1)*gap
        vector<int> bkt_min(n,INT_MAX);
        
        for(int num : nums){
            int i = (double)(num-a)/gap;
            
            if(bkt_min[i] > num) bkt_min[i] = num;
            if(bkt_max[i] < num) bkt_max[i] = num;
        }
        
        int maxgap = 0;
        int pre = bkt_max[0];
        for(int i = 1; i<n; i++){
            if(bkt_max[i] == INT_MIN) continue;
            maxgap = max(maxgap, bkt_min[i]-pre);
            pre = bkt_max[i];
        }
        return maxgap;
    }
};