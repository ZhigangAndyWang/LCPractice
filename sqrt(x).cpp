class Solution {
public:
int mySqrt(int x) {
    if(x<1) return 0;
    if(x==1) return 1;
    //use binary search to find answer, the bound is from 0 to maximun integer
    int end = x;
    int beg = 0;
    int mid = (beg + end) / 2;

    while(beg <= end){
        long long int tmp = (long long)mid * (long long)mid;//in case the mid*mid will overflow

        if( tmp == x )//find sqrt answer
            return mid;
        else if( tmp > x)//mid is too large
            end = mid - 1;
        else //mid*mid < x   -> mid is too small
            beg = mid + 1;
        mid = (beg + end)/2;
    }
    return mid;
}
};
