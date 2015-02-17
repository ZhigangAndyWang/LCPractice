#include <map>
class Solution {
public:
    int romanToInt(string s) {
        map<char,int> valueOfRoman = {{'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000}};
        
        int l = s.length();
        int sum = 0;
        for(int i=0;i<l;i++)
        {
            if(i==l-1) {sum+=valueOfRoman[s[i]];break;}
            if(valueOfRoman[s[i]]<valueOfRoman[s[i+1]]) 
                sum-=valueOfRoman[s[i]];
            else
                sum+=valueOfRoman[s[i]];
        }
        return sum;
        
    }
};