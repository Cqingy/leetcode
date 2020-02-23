#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

string LeftRotateString(string str, int n) {
    if(str.size() == 0 || n <= 0) return str;
    n %= str.size();
    reverse(str.begin(), str.begin() + n);
    reverse(str.begin() + n, str.end());
    reverse(str.begin(), str.end());
    return str;
}

int main(void) {
    string str= "12345";
    cout<<LeftRotateString(str, 2)<<endl;
}