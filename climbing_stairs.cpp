#include <iostream>
#include <unordered_map>
using namespace std;
class Solution {
private:
    unordered_map<int,int> resMap;
public:
    int climbStairs(int n) {
        if(n<1) return 0;
        if(n==1) return 1;
        if(n==2) return 2;
        if(resMap.count(n)) return resMap[n];
        int res = climbStairs(n-1)+climbStairs(n-2);
        resMap[n] = res;
        return res;
    }
};

int main(int argc,char* argv[]){
    Solution s;
    // cout <<"Usage: " << argv[0] << " CLIMBNUM"<<endl;
    int c = atoi(argv[1]);
    cout << s.climbStairs(c)<<endl;
    return 0;
}
