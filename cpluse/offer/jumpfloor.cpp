#include<iostream>
using namespace std;

int jumpFloor(int number) {
    if(number == 1) return 1;
    if(number == 2) return 2;
    int first = 1;
    int second = 2;
    for(int i = 3; i <= number; i++) {
        int temp = first;
        first = second;
        second = second + temp;
    }
    return second;
}

int jumpFloorII(int number) {
    int save[100];
    fill(save, save+100, 0);
    for(int i = 1; i <= number; i++) {
        int temp = 1;
        for(int j = i; j > 0; j--){
            temp += save[i - j];
        }
        save[i] = temp;
    }
    return save[number];
}

int main(void) {
    cout<<jumpFloorII(4)<<endl;
}