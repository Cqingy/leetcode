#include<iostream>
#include<vector>
using namespace std;

bool IsContinuous( vector<int> numbers ) {
    if(numbers.size() == 0) return false;
    sort(numbers.begin(), numbers.end());
    int numberOfzero = 0;
    while(numbers[numberOfzero] == 0) numberOfzero++;
    for(int i = numberOfzero + 1; i < numbers.size(); i++) {
        if(numbers[i] == numbers[i - 1]) return false;
        numberOfzero -= numbers[i] - numbers[i - 1] - 1;
    }
    return numberOfzero >= 0;
}

int main(void) {
    int n;
    vector<int> numbers;

    cin>>n;
    for(int i = 0; i < n; i++) {
        int temp;
        cin>>temp;
        numbers.push_back(temp);
    }
    cout<<IsContinuous(numbers)<<endl;
}
