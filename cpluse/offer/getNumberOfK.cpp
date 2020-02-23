#include<iostream>
#include<vector>
using namespace std;

int getfirst(vector<int> data, int k, int start, int last) {
    int middle = (start + last) >> 1;
    if(start > last) return -1;
    if(data[middle] == k) {
        while(middle > start && data[middle - 1] == k) middle--;
        return middle;
    }
    if(data[middle] < k) return getfirst(data, k, middle + 1, last);
    else return getfirst(data, k, start, middle - 1);
}

int getlast(vector<int> data, int k, int start, int last) {
    int middle = (start + last) >> 1;
    if(start > last) return -1;
    if(data[middle] == k) {
        while(middle < last && data[middle + 1] == k) middle++;
        return middle;
    }
    if(data[middle] < k) return getfirst(data, k, middle + 1, last);
    else return getfirst(data, k, start, middle - 1);
}

int GetNumberOfK(vector<int> data ,int k) {
    if(data.size() == 0) return 0;
    int first = getfirst(data, k, 0, data.size() - 1);
    int last = getlast(data, k, 0, data.size() - 1);
    if(first != -1) return last - first + 1;
    else return 0;
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
    cout<<GetNumberOfK(input, 3);
}