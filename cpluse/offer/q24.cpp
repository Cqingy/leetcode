#include<iostream>
using namespace std;

struct ListNode{
    int val;
    struct ListNode* next;
    ListNode(int x) :  
        val(x),next(NULL){}
};

ListNode* ReverseList(ListNode* pHead) {
    if(pHead == nullptr || pHead->next == nullptr) return pHead;
    ListNode* pNode = pHead->next;
    pHead->next = nullptr;
    while(pNode != nullptr) {
        ListNode* temp = pNode->next;
        pNode->next = pHead;
        pHead = pNode;
        pNode = temp;
    }
    return pHead;
}

int main(void) {
    ListNode* pHead = new ListNode(-1);
    ListNode* pNode = pHead;
    int n;

    cin>>n;
    for(int i = 0; i < n; i++) {
        int temp;
        cin>>temp;
        ListNode* tempNode = new ListNode(temp);
        pNode->next = tempNode;
        pNode = pNode->next;
    }
    pHead = ReverseList(pHead->next);
    while(pHead != nullptr) {
        cout<<pHead->val<<' ';
        pHead = pHead->next;
    }
}

