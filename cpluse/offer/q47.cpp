#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int getMaxValue_solution(vector<vector<int> > values, int rows, int cols) {
    vector<int> result;
    for(int i = 0; i < cols; i++) {
        result.push_back(0);
    }
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            int up = 0;
            int left = 0;
            if(i > 0) up = result[j];
            if(j > 0) left = result[j - 1];
            result[j] = max(up, left) + values[i][j];
        }
    }
    return result.back();
}