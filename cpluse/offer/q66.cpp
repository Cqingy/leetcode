#include<iostream>
#include<vector>
using namespace std;

vector<int> multiply(const vector<int>& A) {
    vector<int> result;
    vector<int> before;
    vector<int> after;
    int before_num = 1;
    int after_num = 1;
    for(int i = 0; i < A.size(); i++) {
        if(i == 0) {
            before.push_back(before_num);
            after.push_back(after_num);
        }else {
            before_num *= A[i - 1];
            after_num *= A[A.size() - i];
            before.push_back(before_num);
            after.push_back(after_num);
        }
    }
    for(int i = 0; i < A.size(); i++) {
        result.push_back(before[i] * after[after.size() - 1 - i]);
    }
    return result;
}

int main(void) {
    int n;
    vector<int> A;

    cin>>n;
    for(int i = 0; i < n; i++) {
        int temp;
        cin>>temp;
        A.push_back(temp);
    }
    A = multiply(A);
    for(int i = 0; i < A.size(); i++) {
        cout<<A[i]<<' ';
    }
}