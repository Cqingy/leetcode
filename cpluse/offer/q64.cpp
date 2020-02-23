#include<iostream>
using namespace std;

int Sum_Solution(int n) {
    int sum = n;
    n && (sum += Sum_Solution(n - 1));
    return sum;
}

int main(void) {
    cout<<Sum_Solution(3)<<endl;
    return 0;
}