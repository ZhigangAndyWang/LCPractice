class Solution {
public:
    int calculate(std::string s) {
        len = s.size();
        int i = 0, sign = 1, num = getNext(s, i), res = 0;
        // s[i] is '+', '-', '*' or '/'
        while (i < len){
            if (s[i] == '+') {
                res += num * sign;
                sign = 1;
                num = getNext(s, ++i);
            }
            else if (s[i] == '-') {
                res += num * sign;
                sign = -1;
                num = getNext(s, ++i);
            }
            else if (s[i] == '*')
                num *= getNext(s, ++i);
            else
                num /= getNext(s, ++i);
        }
        
        res += num * sign;
        return res;
    }
private:
    int len;
    int getNext(std::string &s, int &i) {
        int next = 0;
        while (i < len) {
            if (s[i] >= '0' && s[i] <= '9')
                next = next * 10 + s[i] - '0';
            else if (s[i] != ' ')
                return next;
            ++i;
        }
        return next;
    }
};