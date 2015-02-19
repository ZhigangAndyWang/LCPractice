class Solution {
public:
    int maxSubArray(int A[], int n) {
        int* dp;
        dp = new int[n];
        dp[0] = A[0];
        int res=A[0];
        
        for(int i=1;i<n;i++)
        {
            dp[i] = (dp[i-1]>0?dp[i-1]:0)+A[i];
            if (dp[i]>res) res = dp[i];
        }
        return res;
    }
};