#include<iostream>
#include<string>
using namespace std;

string ReverseSentence(string str) {
    if(str.size() == 0) return str;
    int start = 0;
    int end = 0;
    reverse(str.begin(), str.end());
    while(end <= str.size()) {
        if(str[end] == ' ' || end == str.size()) {
            reverse(str.begin() + start, str.begin() + end);
            end++;
            start = end;
        }
        end++;
    }
    return str;
}

int main(void) {
    string str1 = "hello";
    cout<<ReverseSentence(str1)<<endl;
}