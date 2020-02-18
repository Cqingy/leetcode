#include<iostream>
#include<vector>
using namespace std;

bool VerifySquenceOfBST(vector<int> sequence) {
    vector<int> left, right;
    if(sequence.empty()) return false;
    int root = sequence.back();
    for(int i = 0; i < sequence.size() - 1; i++) {
        if(sequence[i] < root) left.push_back(sequence[i]);
        else break;
    }
    for(int i = left.size(); i < sequence.size() - 1; i++) {
        if(sequence[i] < root) return false;
        else right.push_back(sequence[i]);
    }
    bool result = true;
    if(!left.empty()) result = result && VerifySquenceOfBST(left);
    if(!right.empty()) result = result && VerifySquenceOfBST(right);
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
    cout<<VerifySquenceOfBST(input)<<endl;
    return 0;
}