#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};

vector<int> printListFromTailToHead(ListNode* head) {
    vector<int> result;
    if(head == nullptr)return result;
    if(head->next != nullptr){
        result = printListFromTailToHead(head->next);
    }
    result.push_back(head->val);
    return result;
}

int main(void){
    vector<int> a;
    int n;
    return 0;
}
