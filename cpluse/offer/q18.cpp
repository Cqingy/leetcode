#include<iostream>
#include<vector>
using namespace std;

struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};

void deleteNode(ListNode* &pHead, ListNode* pToBeDelete) {
    if(pHead == nullptr) return;
    if(pToBeDelete->next != nullptr){
        ListNode* temp = pToBeDelete->next;
        pToBeDelete->val = pToBeDelete->next->val;
        pToBeDelete->next = pToBeDelete->next->next;
        delete temp;
        temp = nullptr;
    }
    else if(pToBeDelete == pHead) {
        pHead = nullptr;
    }
    else {
        ListNode* temp = pHead;
        while(temp->next != pToBeDelete) {
            temp = temp->next;
        }
        temp->next = nullptr;
        delete pToBeDelete;
        pToBeDelete = nullptr;
    }
}

ListNode* deleteDuplication(ListNode* pHead) {
    if(pHead == nullptr || pHead->next == nullptr)return pHead;
    ListNode* newHead = new ListNode(-1);
    ListNode* pre = newHead;
    ListNode* pNode = pHead;
    // ListNode* pNext = pNode->next;
    while(pNode != NULL && pNode->next != NULL) {
        ListNode* pNext = pNode->next;
        if(pNode->val == pNext->val) {
            while(pNext != NULL && pNode->val == pNext->val) {
                pNext = pNext->next;
            }
            pre->next = pNext;
            pNode = pNext;
        }else {
            pre->next = pNode;
            pre = pNode;
            pNode = pNext;
        }
    }
    return newHead->next;
}

void printList(ListNode* pHead) {
    while(pHead != nullptr) {
        cout<<pHead->val<<endl;
        pHead = pHead->next;
    }
}

int main(void) {
    int n;

    cin>>n;
    ListNode* pHead;
    pHead->val = 1;
    pHead->next = nullptr;
    ListNode* pInput = pHead;
    for(int i = 0; i < n; i++) {
        ListNode* temp = new ListNode(i);
        temp->next = nullptr;
        int value;
        cin>>value;
        temp->val = value;
        pInput->next = temp;
        pInput = pInput->next;
    }
    pHead = deleteDuplication(pHead);
    printList(pHead);

    return 0;
}