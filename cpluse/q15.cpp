#include<iostream>
using namespace std;

int  NumberOf1(int n) {
    int num = 0;
    unsigned int sign = 1;
    while(sign){
        if(n & sign) num ++;
        sign = sign<<1;
    }
    return num;
}

int main(void) {
    cout<<NumberOf1(9)<<endl;
}