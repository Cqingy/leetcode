#include<iostream>
#include<vector>
#include<map>
using namespace std;

map<char, int> cnt;
vector<int> data;

void Insert(char ch)
{
    cnt[ch]++;
    if(cnt[ch] == 1) {
        data.push_back(ch);
    } 
}
//return the first appearence once char in current stringstream
char FirstAppearingOnce()
{
    for(int i = 0; i < data.size(); i++) {
        if(cnt[data[i]] == 1) return data[i];
    }
    return '#';
}

int main(void) {
    return 0;
}