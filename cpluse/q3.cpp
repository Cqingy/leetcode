#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

// Parameters:
//        numbers:     an array of integers
//        length:      the length of array numbers
//        duplication: (Output) the duplicated number in the array number
// Return value:       true if the input is valid, and there are some duplications in the array number
//                     otherwise false

bool duplicate(int numbers[], int length, int* duplication){
    if(numbers == nullptr || length <= 0)return false;
    for(int i = 0; i < length; i++){
        if(numbers[i] > length - 1 || numbers[i] < 0)return false;
    }
    for(int i = 0; i < length; i++){
        while(numbers[i] != numbers[numbers[i]]){
            int temp = numbers[i];
            numbers[i] = numbers[numbers[i]];
            numbers[temp] = temp;
        }
        if(i != numbers[i]){
            *duplication = numbers[i];
            return true;
        }
    }
    return false;
}

int main(void){
    int n;
    int* duplication;
    bool result;

    *duplication = 1;
    // vector<int> input;
    int input[20];
    cin>>n;
    for(int i = 0; i < n; i++){
        cin>>input[i];
        // int temp;
        // cin>>temp;
        // input.push_back(temp);
    }
    result = duplicate(input, n, duplication);
    cout<<result<<'\n';
    cout<<*duplication<<'\n';
    // cout<<input[0]<<'\n';
}