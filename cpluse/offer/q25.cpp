#include<iostream>
using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x) :
        val(x), next(NULL){}
};

ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
{
    ListNode* MergedList = new ListNode(-1);
    ListNode* pNode = MergedList;
    while(pHead1 != nullptr && pHead2 != nullptr) {
        if(pHead1->val < pHead2->val) {
            pNode->next = pHead1;
            pHead1 = pHead1->next;
        }else{
            pNode->next = pHead2;
            pHead2 = pHead2->next;
        }
        pNode = pNode->next;
    }
    if(pHead1 == nullptr) {
        pNode->next = pHead2;
    }
    if(pHead2 == nullptr) {
        pNode->next = pHead1;
    }

    return MergedList->next;
}