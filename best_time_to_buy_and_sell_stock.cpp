class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int res = 0;
        int highest = INT_MIN;
        
        int n = prices.size();
        if (n==0) return res;
        
        highest = prices[n-1];
        for(int i=n-2;i>=0;i--)
        {
            highest = (prices[i]>highest? prices[i]:highest);
            int temp = highest - prices[i];
            res = max(res,temp);
        }
        return res;
    }
};