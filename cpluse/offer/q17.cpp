#include<iostream>
#include<string>
#include<vector>
using namespace std;

bool Increment(vector<char> &number) {
    // vector<int>::iterator it;
    bool isoverflow = false;
    int takeover = 0;
    for(int i = number.size()-1; i >= 0; i--) {
        int temp = number[i] - '0' + takeover;
        if(i == number.size() - 1)temp += 1;
        if(temp < 10){
            number[i] = temp + '0';
            break;
        }else{
            if(i == 0){
                isoverflow = true;
                break;
            }
            temp -= 10;
            takeover += 1;
            number[i] = temp + '0';
        }
    }
    return isoverflow;
}

void printNumber(vector<char> number) {
    bool flag = false;
    for(int i =0; i < number.size(); i++) {
        if(number[i] != '0')flag=true;
        if(flag)cout<<number[i];
    }
    if(!flag)cout<<'0';
    cout<<endl;
}

void print1toN(int n) {
    vector<char> number;
    for(int i = 0; i < n; i++) {
        number.push_back('0');
    }
    while(!Increment(number)) {
        printNumber(number);
    }
}

int main(void) {
    vector<char> number;
    int n;
    cin>>n;
    print1toN(n);
    // printNumber(number);
    // cout<<number.size()<<endl;
    return 0;
}