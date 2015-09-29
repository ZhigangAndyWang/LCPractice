class Solution {
public:
    int countDigitOne(int n) {
        int ones = 0;
        int a,b; //a represents the digit part larger than m, b is the part smaller than m
        for(long m = 1; m <= n ; m*=10){
            a = n/m;
            b = n%m;
            int lda = a%10; //lastDigitOfA
            if (lda == 0) ones += m*(a/10);
            else if(lda > 1) ones += m*(a/10 + 1);
            else if(lda == 1) ones += m*(a/10) + b+1;
            
        }
        return ones;
    }
};