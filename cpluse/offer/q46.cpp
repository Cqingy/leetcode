#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int GetTranslationCount(int number) {
    if(number < 0) return 0;
    string num = to_string(number);
    if(num.size() == 1) return 1;
    vector<int> result;
    result.push_back(1);
    string temp = num.substr(num.size() - 2, 2);
    if(atoi(temp.c_str()) > 10 && atoi(temp.c_str()) < 26) {
        result.push_back(2);
    }else{
        result.push_back(1);
    }
    for(int i = num.size() - 3; i >= 0; i--) {
        string temp = num.substr(i, 2);
        if(atoi(temp.c_str()) > 10 && atoi(temp.c_str()) < 26) {
            result.push_back(result.back() + result[result.size()-2]);
        }else{
            result.push_back(result.back());
        }
    }
    return result.back();
}

int main(void) {
    cout<<GetTranslationCount(123)<<endl;
}