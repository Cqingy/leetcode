#include<iostream>
#include<vector>
using namespace std;

bool IsPopOrder(vector<int> pushV,vector<int> popV) {
    vector<int> tempV;
    int pop_index = 0;
    for(int i = 0; i < pushV.size(); i++){
        tempV.push_back(pushV[i]);
        while(tempV.size() != 0 && tempV.back() == popV[pop_index]) {
            tempV.pop_back();
            pop_index++;
        }
    }
    if(tempV.empty()) return true;
    return false;
}

int main(void) {
    vector<int> pushV, popV;
    int n;

    cin>>n;
    for(int i = 0; i < n ;i++) {
        int temp;
        cin>>temp;
        pushV.push_back(temp);
    }
    for(int i = 0; i < n; i++) {
        int temp;
        cin>>temp;
        popV.push_back(temp);
    }
    cout<<IsPopOrder(pushV, popV)<<endl;
    // cout<<pushV.back()<<endl;
}