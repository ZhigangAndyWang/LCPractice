#include <iostream>
#include <vector>
#include <map>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        int n = numbers.size();
        map<int , int> findmap;
        vector<int> sol;
        map<int , int> :: iterator it;
        
        for (int i=0;i<numbers.size();i++){

            findmap.insert(pair<int,int>(numbers[i],i));
            it = findmap.find(target-numbers[i]);
            if(it!=findmap.end() && it->first+numbers[i]==target && it->second!=i)
            {
                sol.push_back(min(i+1,it->second+1));
                sol.push_back(max(i+1,it->second+1));
            }
        }
        return sol;
    }
};


int main(){
    Solution s;
    int vv[4] = {0,4,3,0};
    std::vector<int> numbers;
    numbers.assign(&vv[0],&vv[0]+4);
    int target = 0;

    std::vector<int> v = s.twoSum(numbers,0);
    cout << v[0] << " "<<v[1];
    return 0;
}
