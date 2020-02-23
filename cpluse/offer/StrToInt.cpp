#include<iostream>
#include<vector>
#include<string>
using namespace std;

int StrToInt(string str) {
    if(str.size() == 0) return 0;
    int flag = 1;
    if(str[0] == '+') {
        flag = 1;
        str.erase(str.begin());
    }else if(str[0] == '-') {
        flag = -1;
        str.erase(str.begin());
    }
    if(str.size() == 0) return 0;
    int result = 0;
    for(int i = 0; i < str.size(); i++) {
        if(str[i] < '0' || str[i] > '9') return 0;
        int temp = str[i] - '0';
        if(result >= INT_MAX / 10 + (((flag + 1)/2 + temp > 8)?1:0)) return 0;
        result = result * 10 + temp;
    }
    return flag * result;
}

int main(void) {
    string input = "+2147483647";
    cout<<StrToInt(input)<<endl;
}