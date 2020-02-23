#include<iostream>
#include<vector>
#include<queue>
using namespace std;

priority_queue<int, vector<int>, greater<int> > q1;
priority_queue<int, vector<int>, less<int> > q2;

void Insert(int num)
{
    if(q1.empty() || num > q1.top()) q1.push(num);
    else q2.push(num);
    if(q1.size() == q2.size() + 2) {
        q2.push(q1.top());
        q1.pop();
    }
    if(q1.size() < q2.size()) {
        q1.push(q2.top());
        q2.pop();
    }
}

double GetMedian()
{ 
    return (q1.size() > q2.size()) ? q1.top() : (q1.top() + q2.top()) * 1.0/ 2;
}

int main(void) {
    int a[10] = {5,2,3,4,1,6,7,0,8};

    for(int i = 0; i < 9; i++){
        Insert(a[i]);
        cout<<GetMedian()<<endl;
    }
}