#include<iostream>
#include<vector>
using namespace std;

vector<int> FindNumbersWithSum(vector<int> array,int sum) {
    int min_mul = 1000000;
    int min1 = 0;
    int min2 = 0;
    int start = 0;
    int end = array.size() - 1;
    while(start < end) {
        if(array[start] + array[end] == sum) {
            if(array[start] * array[end] < min_mul) {
                min_mul = array[start] * array[end];
                min1 = array[start];
                min2 = array[end];
            }
        }
        if(array[start] + array[end] > sum) end--;
        else start ++;
    }
    vector<int> result;
    if(min_mul != 1000000) {
        result.push_back(min1);
        result.push_back(min2);
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
    input = FindNumbersWithSum(input, 4);
    for(int i = 0; i < input.size(); i++) {
        cout<<input[i]<<' ';
    }
}