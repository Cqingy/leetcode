#include<iostream>
#include<vector>
using namespace std;

int InverseMerge(vector<int> &data, vector<int> &copy, int start, int end) {
    if(start >= end) {
        return 0;
    };
    int middle = (start + end) >> 1;
    int left = InverseMerge(data, copy, start, middle);
    int right = InverseMerge(data, copy, middle + 1, end);
    int i = middle;
    int j = end;
    int num = (left + right) % 1000000007;
    int indexOfcopy = end;

    while(i >= start && j > middle) {
        if(data[i] < data[j]) copy[indexOfcopy--] = data[j--];
        else {
            copy[indexOfcopy--] = data[i--];
            num += j - middle;
            if(num > 1000000007) num %= 1000000007;
        }
    }
    while(i >= start) copy[indexOfcopy--] = data[i--];
    while(j > middle) copy[indexOfcopy--] = data[j--];
    for(int i = start; i <= end; i++) data[i] = copy[i];
    return (num) % 1000000007;
}

int InversePairs(vector<int> data) {
    if(data.size() == 0) return 0;
    vector<int> copy;
    for(int i = 0; i < data.size(); i++) copy.push_back(data[i]);
    int count = InverseMerge(data, copy, 0, data.size() - 1);
    return count;
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
    cout<<InversePairs(input)<<endl;
}