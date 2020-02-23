#include<iostream>
#include<vector>
using namespace std;

unsigned int FindFirstBit1(int num) {
    int index = 0;
    while(((num & 1) == 0) && (index < 8 * sizeof(int))) {
        num >>= 1;
        index++;
    }
    return index;
}

bool judge(int data, int index) {
    data = data >> index;
    return data & 1;
}

void FindNumsAppearOnce(vector<int> data,int* num1,int *num2) {
    int result = 0;
    for(int i = 0; i < data.size(); i++) {
        result ^= data[i];
    }
    unsigned int indexOf1 = FindFirstBit1(result);
    *num1 = 0;
    *num2 = 0;
    for(int i = 0; i < data.size(); i++) {
        if(judge(data[i], indexOf1)) {
            *num1 ^= data[i];
        }else {
            *num2 ^= data[i];
        }
    }
}

int main(void) {
    // int n;
    // int* num1;
    // int* num2;
    // vector<int> data;
    // cin>>n;
    // for(int i = 0; i < n; i++) {
    //     int temp;
    //     cin>>temp;
    //     data.push_back(temp);
    // }
    // FindNumsAppearOnce(data, num1, num2);
    // cout<<num1<<' '<<num2<<endl;
}