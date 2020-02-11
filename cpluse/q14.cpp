#include<iostream>
using namespace std;

int cutRope(int number) {
    int result[70];
    if(number == 2)return 1;
    if(number == 3)return 2;
    result[1] = 1;
    result[2] = 2;
    result[3] = 3;
    for(int i = 4; i <= number; i++){
        int max_num = 0;
        for(int j = 1; j < i; j++){
            int temp = j * result[i - j];
            if(temp > max_num) max_num = temp;
        }
        result[i] = max_num;
    }
    return result[number];
}

int main(void){
    cout<<cutRope(8)<<endl;
}