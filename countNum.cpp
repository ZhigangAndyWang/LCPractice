#include <iostream>
#include <random>
#include <time.h>
using namespace std;

int main(){
    int total = 100000;
    int count1 = 0;
    int count2 = 0;
    int count3 = 0;
    double sum;

    srand (time(NULL));
    double temp;

    for(int i = 0; i < total; i++){
        //generate random number in [-2,2]
        temp = (rand()/(double)(RAND_MAX));
        temp = temp * 4 - 2;
        //cout << temp <<endl;
        if(temp < -1){
            count1++;
        }
        else if(temp <= 1){
            count2 += 1;
        }
        else{
            count3++;
        }
        sum += temp;
    }
    double ave = sum / double(total);

    cout << "average is :" << ave << endl;
    cout << "num x < 1 is :" << count1 << endl;
    cout << "num -1<=x<= 1 is :" << count2 << endl;
    cout << "num x > 1 is :" << count3 << endl;
    return 0;
}
