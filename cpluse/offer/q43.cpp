#include<iostream>
#include<vector>
using namespace std;

int powerbase10(int n){
    int result = 1;
    for(int i = 0; i < n; i++) {
        result *= 10;
    }
    return result;
}

int NumberOf1Between1AndN_Solution_v1(int n)
{
    if(n <= 0) return 0;
    if(n < 10) return 1;
    int length = 1;
    int temp = 10;
    for(temp = 10; temp <= n; temp *= 10) {
        length++;
    }
    int num = 0;
    while(length > 0) {
        --length;
        temp /= 10;
        int a = n / temp;
        if(a > 1) num += temp;
        else if(a == 1 && length != 0) num += n % temp + 1;
        else if(a == 1 && length == 0) num += n % temp;
        num += length * powerbase10(length - 1) * a;
        n = n % temp;
    }
    return num;
}

int NumberOf1Between1AndN_Solution(int n)
{
    if(n <= 0) return 0;
    if(n < 10) return 1;
    int length = 1;
    int temp = 10;
    int num = 0;
    while(temp <= n * 10) {
        int a = n / temp;
        int b = n % temp;
        num += a * temp / 10;
        if(b >= temp * 2 / 10) num += temp / 10;
        else if(b >= temp / 10 && temp == 10) num += b % (temp / 10);
        else if(b >= temp / 10) num += b % (temp / 10) + 1;
        temp *= 10;
    }
    return num;
}

int main(void) {
    cout<<NumberOf1Between1AndN_Solution(11)<<endl;
}