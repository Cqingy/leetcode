#include<iostream>
#include<vector>
using namespace std;

int MoreThanHalfNum_Solution(vector<int> numbers) {
    if(numbers.size() == 0) return 0;
    int result = numbers[0];
    int times = 1;
    for(int i = 1; i < numbers.size(); i++) {
        if(times == 0) {
            result = numbers[i];
            times = 1;
        }
        else if(numbers[i] == result) {
            times++;
        }else{
            times--;
        }
    }
    times = 0;
    for(int i = 0; i < numbers.size(); i++) {
        if(numbers[i] == result) times++;
    }
    if(times > numbers.size() >> 1) return result;
    else return 0;
}