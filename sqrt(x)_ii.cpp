class Solution {
public:
    int mySqrt(int x) {
        //Considering the Function F(p) = p^2 -x = 0, Using newton's method to find solution
        double delta = 0.00001;
        double res = x;
        while(abs(res*res-x) > delta){
            res = (res + x/res ) / 2;
        }
        return res;
    }
};