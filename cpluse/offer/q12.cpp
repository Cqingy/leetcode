#include<iostream>
#include<algorithm>
using namespace std;

bool hasPathCore(char* matrix, int rows, int cols, char* str, int curr_rows, int curr_cols, bool* visit){
    if(*str == '\0')return true;
    if(curr_rows >= rows || curr_rows < 0 || curr_cols < 0 || curr_cols >= cols || visit[cols * curr_rows + curr_cols])return false;
    if(*str != matrix[cols * curr_rows + curr_cols])return false;
    visit[cols * curr_rows + curr_cols] = true;
    bool result =  hasPathCore(matrix, rows, cols, str + 1,curr_rows - 1, curr_cols, visit) || \
           hasPathCore(matrix, rows, cols, str + 1, curr_rows + 1, curr_cols, visit) || \
           hasPathCore(matrix, rows, cols, str + 1, curr_rows, curr_cols - 1, visit) || \
           hasPathCore(matrix, rows, cols, str + 1, curr_rows, curr_cols + 1, visit);
    if(!result){
        visit[cols * curr_rows + curr_cols] = false;
    }
    return result;
}

bool hasPath(char* matrix, int rows, int cols, char* str) {
    if(matrix == nullptr || rows < 1 || cols < 1 || str == nullptr)return false;
    bool* visit = new bool[rows * cols];
    fill(visit, visit + rows * cols, false);

    for(int i = 0; i < rows; i ++){
        for(int j = 0; j < cols; j++){
            if(hasPathCore(matrix, rows, cols, str, i, j, visit)) return true;
        }
    }
    return false;
}

int main(void){
    char matrix[50] = "ABCEHJIGSFCSLOPQADEEMNOEADIDEJFMVCEIFGGS";
    // fill(a, a + 10, 1);
    int rows = 5;
    int cols = 8;
    char str[20] = "SLHECCEIDEJFGGFIE";
    cout<<hasPath(matrix, rows, cols, str)<<endl;
}