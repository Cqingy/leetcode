#include<iostream>
#include<vector>
using namespace std;

void reOrderArray_v1(vector<int> &array) {
    int end = array.size() - 1;
    int begin = 0;
    while(end > begin) {
        if(array[begin] % 2 == 0 && array[end] % 2 == 1) {
            int temp = array[begin];
            array[begin] = array[end];
            array[end] = temp;
        }
        else if(array[begin] % 2 == 0) end--;
        else if(array[end] % 2 == 1) begin++;
        else {
            begin++;
            end--;
        }
    }
}

void reOrderArray_v2(vector<int> &array) {
    int even = 0;
    int odd = 0;
    while(even < array.size() && odd < array.size()) {
        while(even < array.size() && array[even] % 2 != 0) {
            even++;
        }
        odd = even;
        while(odd < array.size() && array[odd] % 2 != 1) {
            odd++;
        }
        // 插入排序
        if(even < array.size() && odd < array.size()) {
            int temp = array[odd];
            for(int i = odd; i > even; i--) {
                array[i] = array[i-1];
            }
            array[even] = temp;
        }
    }
}

void reOrderArray(vector<int> &array) {
    vector<int> new_array;
    for(int i = 0; i < array.size(); i++) {
        if((array[i] & 0x1) == 1) new_array.push_back(array[i]);
    }
    for(int i = 0; i < array.size(); i++) {
        if((array[i] & 0x1) == 0) new_array.push_back(array[i]);
    }
    array = new_array;
}

int main(void) {
    vector<int> array;
    int n;
    cin>>n;
    for(int i = 0; i < n; i++) {
        int temp;
        cin>>temp;
        array.push_back(temp);
    }
    reOrderArray(array);
    for(int i = 0; i < array.size(); i++) {
        cout<<array[i]<<endl;
    }
}