class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> maxpL(n,0); //max profit left, from 0-i
        vector<int> maxpR(n,0); //max prifit right, from i-n-1
        
        int res = 0;
        if (prices.size() < 2) return res;
        
        int minNum = prices[0];
        for(int i = 1; i < prices.size() ; i++){
            maxpL[i] = max(maxpL[i-1], prices[i]-minNum);
            minNum = min(minNum, prices[i]);
        }
        
        int maxNum = prices.back();
        for(int j = prices.size()-2; j >= 0 ; j--){
            maxpR[j] = max(maxpR[j+1], maxNum - prices[j]);
            maxNum = max(maxNum,prices[j]);
        }
        
        for(int i = 0; i < prices.size(); i++){
            res = max(res, maxpL[i]+maxpR[i]);
        }
        return res;
    }
};