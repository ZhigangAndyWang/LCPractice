class Solution {
public:
    double pow(double x, int n) {
        if(n==0) return 1;
        if(n==1) return x;
        // cannot use pow(1/x,-n) since it will cause overflow
        //-INT_MIN =INT_MIN
        //https://oj.leetcode.com/discuss/15202/00000-2147483648-test-case-failed-code-passed-another-code
        if(n<0) {n=-n; x=1/x;} 
        return ( n&1 ? x*pow(x*x,n/2):pow(x*x,n/2));
    }
};