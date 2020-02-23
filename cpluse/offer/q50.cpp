#include<iostream>
#include<string>
#include<map>
using namespace std;

int FirstNotRepeatingChar(string str) {
    map<char, int> hash;
    for(int i = 0; i < str.size(); i++) {
        hash[str[i]]++;
    }
    for(int i = 0; i < str.size(); i++) {
        if(hash[str[i]] == 1)return i;
    }
    return -1;
}

int main(void) {
    string a = "124";
    return 0;
}