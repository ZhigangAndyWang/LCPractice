#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;


class Solution {
public:
    int numDistinct(string s, string t) {
        int m = s.size();
        int n = t.size();
        if(m == 0 || n == 0) return 0;
        int res = 0;
        vector<unordered_map<int,int> >  dp(n+1);
        dp[0].insert(make_pair(-1,1));
        
        for(int i = 0; i < n ; i++){
            //calculate dp[i+1], which stands for the solutions of distinct subsequences of T.substr(0,i+1) in S
            for(auto it = dp[i].begin(); it!= dp[i].end(); it++){
                int endIdx = it->first;
                int num = it->second;
                for(int j = endIdx+1; j < m; j++){
                    if(s[j] == t[i]){
                        cout << "now j,i:" << j << i <<endl;
                        //increseert the solution with endIdx = j to dp[i+1]
                        if( dp[i+1].find(j) == dp[i+1].end() ){
                            dp[i+1].insert(make_pair(j,num));
                        }
                        //increse
                        else{
                            dp[i+1][j] += num;
                        }
                    }
                }
            }
        }
        for(auto it = dp[n].begin(); it!= dp[n].end(); it++){
            int num = it->second;
            res += num;
        }
        return res;
        
    }
};

int main(){
    Solution s;
    int res = s.numDistinct("ccc","c");
    cout << "results:"<<endl;
    cout << res<<endl;
    return 0;

}