#include<iostream>
using namespace std;

int LastRemaining_Solution(int n, int m)
{
    if(n < 1 || m < 1) return -1;
    int result = 0;
    for(int i = 2; i <= n; i++) {
        result = (result + m) % i;
    }
    return result;
}

int main(void) {
    cout<<LastRemaining_Solution(5,2)<<endl;
}