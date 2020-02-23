#include<iostream>
#include<vector>
using namespace std;

void MergeSort(vector<int> &array, int start, int end) {
    if(start >= end) return;
    int middle = (start + end) >> 1;
    int left = start;
    int right = middle + 1;
    MergeSort(array, start, middle);
    MergeSort(array, middle + 1, end);
    vector<int> temp;
    while(left <= middle && right <= end) {
        if(array[left] < array[right]) {
            temp.push_back(array[left]);
            left++;
        }
        else {
            temp.push_back(array[right]);
            right++;
        }
    }
    while(left <= middle) temp.push_back(array[left++]);
    while(right <= end) temp.push_back(array[right++]);
    array.erase(array.begin() + start, array.begin() + end + 1);
    array.insert(array.begin() + start, temp.begin(), temp.end());
}

int main(void) {
    vector<int> input;
    vector<int> result;
    int n;

    cin>>n;
    for(int i = 0; i < n; i++) {
        int temp;
        cin>>temp;
        input.push_back(temp);
    }
    MergeSort(input, 0, input.size() - 1);
    for(int i = 0; i < input.size(); i++) {
        cout<<input[i]<<' ';
    }
}