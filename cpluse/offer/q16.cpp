#include<iostream>
#include<algorithm>
using namespace std;

double unsignedPower(double base, int exponent){
    double sum = 1.0;
    for(int i = 0; i < exponent; i++){
        sum *= base;
    }
    return sum;
}

double unsignedPower_v2(double base, int exponent) {
    double sum = 1.0;
    if(exponent == 1) return base;
    if(exponent == 0) return 1;
    double result = unsignedPower_v2(base, exponent >> 1);
    result *= result;
    if((exponent & 0x1) == 1) result *= base;
    return result;
}

double Power(double base, int exponent) {
    if(base == 0) return 0;
    if(base - 0.0 < 0.000001 && base - 0.0 > -0.0000001)return 1.0;
    else if(exponent > 0){
        return unsignedPower_v2(base, exponent);
    }
    else{
        return 1.0 / unsignedPower_v2(base, -exponent);
    }
}

int main(void){
    cout<<Power(2, -3)<<endl;
    // cout<<1.0/1.1<<endl;
}
