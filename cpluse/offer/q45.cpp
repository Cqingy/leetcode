#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

bool cmp(string a, string b) {
    int i;
    int j;
    while(i < a.size() && j < b.size()) {
        if(a[i] == b[j]){
            i++;
            j++;
        }else {
            return a[i] < b[j];
        }
    }
    if(i == a.size()) return b > a;
    else return a > b;
}

string PrintMinNumber(vector<int> numbers) {
    vector<string> a;
    for(int i = 0; i < numbers.size(); i++) {
        a.push_back(to_string(numbers[i]));
    }
    sort(a.begin(), a.end(), cmp);
    string result = "";
    for(int i = 0; i < a.size(); i ++) {
        result += a[i];
    }
    return result;
}

int main(){
    vector<int> input;
    int n;

    cin>>n;
    for(int i = 0; i < n; i++) {
        int temp;
        cin>>temp;
        input.push_back(temp);
    }
    cout<<PrintMinNumber(input)<<endl;
}