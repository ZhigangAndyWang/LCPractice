class Solution {
private:
    int gcd(int a, int b){
        if( b == 0 ) return a;
        else{
            return gcd( b, a%b );
        }
    }
    
public:
    void rotate(vector<int>& nums, int k) {
        int temp = 0;
        int prev = 0;
        int n = nums.size();
        int loopsNeeded = gcd(n,k);     //coz n/(#of nodes each loop passed) = n/(n*k/gcd /k) = gcd
        for(int i=0;i<loopsNeeded;++i){
            int j = i;
            prev = nums[i];
            while(true){
                temp = nums[(j+k)%n];
                nums[(j+k)%n] = prev;
                prev = temp;
                j = (j+k)%n;
                if( j==i ){
                    break;
                }
            }
        }
    }
};