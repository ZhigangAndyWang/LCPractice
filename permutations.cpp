class Solution {
public:
    vector<vector<int> > permute(vector<int> &num) {
        vector<vector<int>> res;
        int n = num.size();
        if(!n) return res;
        
        vector<vector<vector<int>>> dp;
        dp.push_back(vector<vector<int>>(1,vector<int>(1,num[0])));
        
        for(int i=1;i<n;i++)
        {
            vector<vector <int> > temp;
            temp.clear();
            for(int j=0;j<dp[i-1].size();j++)
            {
                dp[i-1][j].insert(dp[i-1][j].begin(),num[i]);
                temp.push_back(dp[i-1][j]);
                for(int k=1;k<dp[i-1][j].size();k++)
                {
                    swap(dp[i-1][j][k-1],dp[i-1][j][k]);
                    temp.push_back(dp[i-1][j]);
                }
            }
            dp.push_back(temp);
        }
        
        res = dp[n-1];
        return res;
    }
};