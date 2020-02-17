#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

bool Find(int target, vector<vector<int> > array) {
    if(array.size() <= 0 || array[0].size() <= 0)return false;
    int h = array.size();
    int b = array[0].size();
    int curr_b = b - 1;
    int curr_h = 0;
    while(curr_h < h && curr_b >= 0) {
        int temp = array[curr_h][curr_b];
        if(target > temp)curr_h += 1;
        else if(target < temp)curr_b -=1;
        else{
            return true;
        }
    }
    return false;
}

int main(void){
    int target;
    int n;
    vector<vector<int> > array;

    cin>>target>>n;
    for(int i = 0; i < n; i++){
        vector<int> temp;
        for(int j = 0; j < n; j++){
            int number;
            cin>>number;
            temp.push_back(number);
        }
        array.push_back(temp);
    }
    cout<<Find(target, array)<<'\n';
    return 0;
}