#include <iostream>
using namespace std;

int main(){

    char str[] = "hello";

    for (int i =0;i < sizeof(str)/sizeof(str[0]);i++){
        if (str[i] == '\0')
            cout<< " null";
        else
            cout << str[i]<<" ";
    }


    cout << "lastdight: "<< str[5] <<endl;
    return 0;
}
