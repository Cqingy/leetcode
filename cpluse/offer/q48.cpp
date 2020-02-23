#include<iostream>
#include<string>
#include<vector>
using namespace std;

int longestSubstring(string str){ 
    if(str.size() == 0) return 0;
    int currlenth = 0;
    int maxlenth = 0;
    vector<int> visit;
    for(int i = 0; i < 26; i++) visit.push_back(-1);
    for(int i = 0; i < str.size(); i++) {
        int prePos = visit[str[i] - 'a'];
        if(prePos < 0 || i - prePos > currlenth) currlenth++;
        else{
            currlenth = i - prePos;
        }
        if(currlenth > maxlenth) maxlenth = currlenth;
        visit[str[i] - 'a'] = i;
    }
    return maxlenth;
}

int main(void) {
    string input = "abcdeag";
    cout<<longestSubstring(input)<<endl;
}