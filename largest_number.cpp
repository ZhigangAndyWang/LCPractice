class Solution {
private:
    static bool comp(int a, int b){
        if(a==b) return 0;
        int n1 = 10, n2 = 10;
        while(n1 <= a) n1*=10;
        while(n2 <= b) n2 *=10;
        if ( n1 == n2 ) return a > b;
        else
            return (a*n2+b)>(b*n1+a) ;
    }

public:
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end(),comp);
        string res = "";
        for(int a : nums){
            res += to_string(a);
        }
        //for the case [0,0],[0],...
        while(res[0] == '0' && res.size() > 1){
            res = res.substr(1);
        }
        return res;
    }
};