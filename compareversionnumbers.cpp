#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int compareVersion(string version1, string version2) {

        while(true){
            if(version1.length()==0 || version2.length()==0) return 0;

            size_t find1 = version1.find("."); 
            size_t find2 = version2.find("."); 
            if(find1 == string::npos) { find1 = version1.length();}
            if(find2 == string::npos) { find2 = version2.length();}

            string num1 = version1.substr(0,find1);
            string num2 = version2.substr(0,find2);
            cout<<num1<<" and "<<num2<<endl;

            if(num1.length()>num2.length()) {num2.append(num1.length()-num2.length(),'0');}
            if(num1.length()<num2.length()) {num1.append(num2.length()-num1.length(),'0');}

            int n1 = atoi(num1.c_str());
            int n2 = atoi(num2.c_str());

            if(n1 > n2) return 1;
            if(n1 < n2) return -1;
            if(n1==n2 && version1.length()==find1 && version2.length()==find2) return 0;
            if(version1.length()==find1) {
                version1 = "0";
            }
            else{
                version1 = version1.substr(find1+1);
            }
            if(version2.length()==find2) {
                version2 = "0";
            }
            else{
                version2 = version2.substr(find2+1);
            }
            cout<<version1<<" andv "<<version2<<endl;

        }


        return 0;
    }
};

int main(){
    Solution s;
    cout << s.compareVersion("1","1.1");
    return 1;
}
