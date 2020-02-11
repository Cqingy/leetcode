#include<iostream>
using namespace std;

bool judge(int curr_row, int curr_col, int threshold){
    int num = 0;
    while(curr_row > 0){
        num += curr_row % 10;
        curr_row /= 10;
    }
    while(curr_col > 0){
        num += curr_col % 10;
        curr_col /= 10;
    }
    return num <= threshold;
}

int movingCountCore(int threshold, int rows, int cols, int curr_row, int curr_col, bool* visit) {
    if(curr_col < 0 || curr_col >= cols || curr_row < 0 || curr_row >= rows || !judge(curr_row, curr_col, threshold) || visit[curr_row * cols + curr_col]) return 0;
    visit[cols * curr_row + curr_col] = true;
    return 1 + \
        movingCountCore(threshold, rows, cols, curr_row + 1, curr_col, visit) + \
        movingCountCore(threshold, rows, cols, curr_row - 1, curr_col, visit) + \
        movingCountCore(threshold, rows, cols, curr_row, curr_col + 1, visit) + \
        movingCountCore(threshold, rows, cols, curr_row, curr_col - 1, visit);
}

int movingCount(int threshold, int rows, int cols){
    bool* visit = new bool[rows * cols];
    fill(visit, visit + rows * cols, false);
    return movingCountCore(threshold, rows, cols, 0, 0, visit);
}

int main(void){
    int threshold = 10;
    int rows = 5;
    int cols = 5;
    cout<<movingCount(threshold, rows, cols)<<endl;
}