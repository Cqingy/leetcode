#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;

void dfs(string str, int num, vector<string> &result) {
    if(num == str.size() - 1) {
        if((find(result.begin(), result.end(), str) == result.end())) {
            result.push_back(str);
            return;
        }
    }
    for(int i = num; i < str.size(); i++) {
        swap(str[num], str[i]);
        dfs(str, num + 1, result);
        swap(str[num], str[i]);
    }
}

vector<string> Permutation(string str) {
    vector<string> result;
    dfs(str, 0, result);
    sort(result.begin(), result.end());
    return result;
}

int main(void) {
    string a = "abc";
    cout<<a<<endl;
    vector<string> result = Permutation(a);
    for(int i = 0; i < result.size(); i++) {
        cout<<result[i]<<endl;
    }
}