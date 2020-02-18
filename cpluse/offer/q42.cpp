#include<iostream>
#include<vector>
using namespace std;

int FindGreatestSumOfSubArray(vector<int> array) {
    vector<int> result;
    for(int i = 0; i < array.size(); i++) {
        result.push_back(array[i]);
    }
    for(int i = 1; i < result.size(); i++) {
        result[i] = max(result[i-1] + result[i], result[i]);
    }
    int maxnum = -10000;
    for(int i = 0; i < result.size(); i ++) {
        if(result[i] > maxnum) maxnum = result[i];
    }
    return maxnum;
}