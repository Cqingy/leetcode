#include<iostream>
#include<vector>
using namespace std;

vector<int> printMatrix(vector<vector<int> > matrix) {
    vector<int> result;
    int rows = matrix.size();
    if(rows == 0) return result;
    int cols = matrix[0].size();
    if(cols == 0) return result;

    int start = 0;
    while(rows > start * 2 && cols > start * 2) {
        int endX = cols - 1 - start;
        int endY = rows - 1 - start;
        for(int i = start; i <= endX; i++){
            result.push_back(matrix[start][i]);
        }
        for(int i = start + 1; i <= endY; i++){
            result.push_back(matrix[i][endX]);
        }
        if(endY > start) {
            for(int i = endX - 1; i > start; i--){
                result.push_back(matrix[endY][i]);
            }
        }
        if(start < endX) {
            for(int i = endY; i > start; i--){
                result.push_back(matrix[i][start]);
            }
        }
        start++;
    }
    return result;
}

int main(void) {
    vector<int> temp;
    vector<vector<int> > input;

    temp.push_back(1);
    temp.push_back(2);
    input.push_back(temp);
    input.push_back(temp);
    temp = printMatrix(input);
    for(int i = 0; i < temp.size(); i++){
        cout<<temp[i]<<' ';
    }
}