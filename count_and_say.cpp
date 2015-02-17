#include <iostream>
using namespace std;
class Solution {
public:
    string countAndSay(int n) {
        string s1="1";
        if(n==1) return s1;
        for(int i=1;i<n;i++)
        {
            string s2="";
            char temp=s1[0];
            int count = 1;
            for(int j=0;j<s1.length();)
            {
                if(j==s1.length()-1 || s1[j]!=s1[j+1])
                {
                    s2+= std::to_string(count)+temp;
                    if(j!=s1.length()-1) temp=s1[j+1];
                    j++;
                    count=1;
                }
                else
                {
                    j++;
                    count++;
                }
            }
            s1=s2;
        }
        return s1;
    }
};


int main(){
    Solution s;
    string c = s.countAndSay(3);
    cout << c;
    return 0;
}

