#include <iostream>
#include <string>
using namespace std;

int main(int argc, char* argv[]){
    int j = 1;
    int *i = &j;
    cout << "*i"<<*i<<endl;
    cout << "i" << i <<endl;
    cout <<"&j" << &j<<endl;
    cout << "&i" << &i <<endl;
    cout << "&*i" << &*i <<endl;
    return 0;
}
