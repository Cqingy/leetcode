#include<iostream>
#include<set>
#include<vector>
#include<functional>
using namespace std;

vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
    vector<int> result_k;
    if(k < 1 || k > input.size()) return result_k;
    multiset<int, greater<int> >result;
    for(int i = 0; i < input.size(); i++) {
        if(result.size() < k){
            result.insert(input[i]);
        }else{
            int maxNum = *result.begin();
            if(input[i] < maxNum) {
                result.erase(result.begin());
                result.insert(input[i]);
            }
        }
    }
    for(multiset<int, greater<int> >::iterator it = result.begin(); it != result.end(); it++){
        result_k.push_back(*it);
    }
    sort(result_k.begin(), result_k.end());
    return result_k;
}

int main(void) {
    vector<int> input;
    int n;
    int k;

    cin>>n>>k;
    for(int i = 0; i < n; i++) {
        int temp;
        cin>>temp;
        input.push_back(temp);
    }
    input = GetLeastNumbers_Solution(input, k);
    for(int i = 0; i < k; i++) {
        cout<<input[i]<<' ';
    }
}
