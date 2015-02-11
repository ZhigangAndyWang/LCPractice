#include <stack>
class Solution {
public:
    bool isValid(string s) {
        stack<char> sta;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='('||s[i]=='{'||s[i]=='[')
            {
                sta.push(s[i]);
                continue;
            }
            if(sta.empty()) return false;
            if(sta.top()=='('&&s[i]!=')') return false;
            if(sta.top()=='['&&s[i]!=']') return false;
            if(sta.top()=='{'&&s[i]!='}') return false;
            sta.pop();
        }
        return sta.empty();
    }
};