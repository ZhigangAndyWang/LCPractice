#include <map>
class Solution {
public:
    int majorityElement(vector<int> &num) {
        map<int,int> hmap;
        while(num.size()!=0)
        {
            int n = num.back();
            num.pop_back();
            
            hmap[n] += 1;
        }
        
        int maxv = 0;
        int res;
        for( map<int,int>::iterator it = hmap.begin();it != hmap.end() ; it++)
        {
            int n = it->first;
            int v = it->second;
            if(v>=maxv)
            {
                maxv = v;
                res = n;
            }
        }
        return res;
    }
};