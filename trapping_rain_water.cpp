class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if(n<2) return 0;
        
        int *lmh = new int[n]; // left most high
        int maxH = height[0];
        for(int i = 1; i<n-1 ; i++){
            lmh[i] = maxH;
            if(height[i] > maxH) 
                maxH = height[i];
        }
        
        int *rmh = new int[n];
        maxH = height[n-1];
        for(int i = n-2;i>0;i--){
            rmh[i] = maxH;
            if(height[i] > maxH)
                maxH = height[i];
        }
        int res = 0;
        for(int i = 1; i<=n-2; i++){
            res += max(0, min(lmh[i],rmh[i])-height[i]);
        }
    
        return res;
    }
    
};