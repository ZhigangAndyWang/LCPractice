class Solution {
public:
    int calculate(string s) {
        
        if (s.empty()) return 0;
        
        stack<int> st;
        int sign = 1;
        int res = 0;
        
        for(int i = 0; i<s.length();i++){
            char c = s[i];
            if (isdigit(c)){
                int cur = c - '0';
                while (i<s.length()-1 && isdigit(s[i+1])){
                    cur = cur*10 + s[++i]-'0';
                }
                res += sign*cur;
            }
            else if (c == '-'){
                sign = -1;
            }
            else if (c == '+'){
                sign = 1;
            }
            else if (c == '('){
                st.push(res);
                st.push(sign);
                res = 0;
                sign = 1;
            }
            else if (c == ')'){
                int a = st.top();
                st.pop();
                int v = st.top();
                st.pop();
                res = a*res + v;
                sign = 1;
            }
        }
        return res;
    }
};