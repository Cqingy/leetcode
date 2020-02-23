#include<iostream>
#include<vector>
#include<deque>
using namespace std;

vector<int> maxInWindows(const vector<int>& num, unsigned int size)
{
    vector<int> result;
    deque<int> temp;

    if(num.size() < size || size <= 0) return result;
    for(int i = 0; i < size; i++) {
        while(!temp.empty() && num[i] > num[temp.back()]){
            temp.pop_back();
        }
        temp.push_back(i);
    }
    result.push_back(num[temp.front()]);
    for(int i = size; i < num.size(); i++) {
        if(i - temp.front() > size - 1) {
            temp.pop_front();
        }
        while(!temp.empty() && num[i] > num[temp.back()]) temp.pop_back();
        temp.push_back(i);
        result.push_back(num[temp.front()]);
    }
    return result;
}

int main(void) {
    vector<int> input;
    int n;

    cin>>n;
    for(int i = 0; i < n; i++) {
        int temp;
        cin>>temp;
        input.push_back(temp);
    }
    input = maxInWindows(input, 3);
    for(int i = 0; i < input.size(); i++){
        cout<<input[i]<<' ';
    }
}