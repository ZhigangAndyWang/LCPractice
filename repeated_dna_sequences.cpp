#include <string>
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> res;
        hash<string> mapping;
        unordered_set<int> freqSet;
        if (s.length()<=10) return res;
        for(int i=0;i<s.length()-9;i++)
        {
            string temp = s.substr(i,10);
            if(freqSet.find(mapping(temp))!=freqSet.end()) 
            {
                if (find(res.begin(),res.end(),temp)==res.end())
                    res.push_back(temp);
            }
            else freqSet.insert(mapping(temp));
        }
        
        return res;
    }
};