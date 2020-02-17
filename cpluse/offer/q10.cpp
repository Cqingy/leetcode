#include<iostream>
#include<algorithm>
using namespace std;

int Fibonacci(int n) {
    if(n == 0)return 0;
    if(n == 1)return 1;
    int pre_num = 0;
    int result = 1;
    for(int i = 0; i < n -1; i ++){
        int temp = result;
        result = pre_num + result;
        pre_num = temp;
    }
    return result;
}

int main(void){
    int n;

    cin>>n;
    cout<<Fibonacci(n)<<endl;
}