#include<iostream>
#include<vector>
using namespace std;

vector<vector<int> > FindContinuousSequence(int sum) {
    vector<vector<int> > result;
    if(sum <= 1) return result;
    int start = 1;
    int end = 2;
    int middle = sum / 2;
    int currsum = 3;

    vector<int> temp;
    temp.push_back(start);
    temp.push_back(end);
    while(start <= middle) {
        if(currsum == sum) {
            result.push_back(temp);
        }
        if(currsum < sum) {
            ++end;
            currsum += end;
            temp.push_back(end);
        }else {
            currsum -= start;
            temp.erase(temp.begin());
            ++start;
        }
    }
    return result;
}