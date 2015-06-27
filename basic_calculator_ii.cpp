#include <iostream>
#include <stack>
using namespace std;
class Solution {
public:
    bool timeToCalculate(char op1, char op2){
        if (op1 == '*' || op1 == '/') return true;
        if (op2 == '+' || op2 == '-') return true;
        return false;
    }
    
    int cal(int a, int b, char op){
        if (op == '+') return a + b;
        else if (op == '-') return a - b;
        else if (op == '*') return a * b;
        else return a / b;
    }
    int calculate(string s) {
        stack<int> nums;
        stack<char> ops;
        int cur = 0;
        
        for(int i = 0; i < s.size(); i++ ){
            char c = s[i];
            if ( c == ' ') continue;
            if ( isdigit(c) ){
                cur = c - '0';
                while( i<s.size()-1 && isdigit(s[i+1]) ){
                    cur = 10*cur + s[++i]-'0'; 
                }
                nums.push(cur);
            }
            if ( i == s.size()-1 || c == '+' || c == '-' || c == '*' || c == '/'){
                while( !ops.empty() && (i==s.size()-1 || timeToCalculate(ops.top(),c) ) ){
                    int b = nums.top();
                    nums.pop();
                    int a = nums.top();
                    nums.pop();
                    char op = ops.top();
                    ops.pop();
                    int tmp = cal(a,b,op);
                    nums.push(tmp);
                }
                if (i == s.size()-1) return nums.top();
                ops.push(c);
            }
        }
        
        return nums.top();
    }
};

int main(){
    Solution s;
    cout << s.calculate("3+3/2*3+6/4") << endl;
}