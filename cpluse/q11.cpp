#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int minNumberInRotateArray(vector<int> rotateArray) {
    int left = 0;
    int right = rotateArray.size() - 1;
    if(right - left <= 1){
        if(rotateArray[right] < rotateArray[left])return rotateArray[right];
        else return rotateArray[left];
    }
    if(rotateArray[left] > rotateArray[right]){
        int mid = (left + right) / 2;
        if(rotateArray[left] <= rotateArray[mid]){
            left = mid;
        }else{
            right = mid;
        }
    }else{
        int minium = rotateArray[left];
        for(int i = left; i <= right; i++){
            if(rotateArray[i] < minium){
                minium = rotateArray[i];
            }
        }
        return minium;
    }
    vector<int> temp;
    for(int i = left; i <= right; i++){
        temp.push_back(rotateArray[i]);
    }
    return minNumberInRotateArray(temp);
}

int main(void){
    vector<int> a;
    int n;
    cin>>n;
    for(int i = 0; i < n; i++){
        int temp;
        cin>>temp;
        a.push_back(temp);
    }
    cout<<minNumberInRotateArray(a)<<endl;
}