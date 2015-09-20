class Solution {
public:
    int candy(vector<int>& ratings) {
        int res = 0;
        int n = ratings.size();
        vector<int> cd(n,0);
        if(n == 0) return 0;
        
        cd[0] = 1;
        for(int i = 1; i < n; i++){
            if (ratings[i] > ratings[i-1] ) cd[i] = cd[i-1]+1;
            if (ratings[i] == ratings[i-1]) cd[i] = 1;
            if (ratings[i] < ratings[i-1]) cd[i] = cd[i-1]-1;
            if ( i < n-1 && ratings[i] < ratings[i-1] && ratings[i] <= ratings[i+1]){//bottom
                reAdjust(cd,i,ratings);
            }
        }
        if(cd[n-1] < cd[n-2]) reAdjust(cd,n-1,ratings);
        
        for(int i : cd){
            res+=i;
        }
        return res;
    }
    
    void reAdjust(vector<int>& cd, int i, vector<int>& ratings){
        int diff = 1-cd[i];
        int k = i;
        for(; k >= 0; k--){
            if( k>0 && ratings[k] >= ratings[k-1]) {
                if(diff>0) cd[k]+= diff;
                break;
            }
            cd[k] += diff;
        }
    }
};