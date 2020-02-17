#include<iostream>
#include<stack>
#include<algorithm>
using namespace std;

class Solution
{
public:
    void push(int node) {
        stack1.push(node);
    }

    int pop() {
        if(stack2.empty()){
            while(stack1.size() > 0){
                int temp = stack1.top();
                stack1.pop();
                stack2.push(temp);
            }
        }
        int result = stack2.top();
        stack2.pop();
        return result;
    }

private:
    stack<int> stack1;
    stack<int> stack2;
};