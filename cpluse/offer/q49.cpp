#include<iostream>
#include<vector>
using namespace std;

int GetUglyNumber_Solution(int index) {
    if(index <= 0) return 0;
    vector<int> ugly;
    int ugly2 = 0;
    int ugly3 = 0;
    int ugly5 = 0;
    ugly.push_back(1);
    while(ugly.size() < index) {
        int new_ugly = min(ugly[ugly2] * 2, min(ugly[ugly3] * 3, ugly[ugly5] * 5));
        ugly.push_back(new_ugly);
        while(ugly[ugly2] * 2 <= new_ugly) ugly2++;
        while(ugly[ugly3] * 3 <= new_ugly) ugly3++;
        while(ugly[ugly5] * 5 <= new_ugly) ugly5++;
    }
    return ugly.back();
}

int main(void) {
    cout<<GetUglyNumber_Solution(5)<<endl;
}