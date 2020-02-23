#include<iostream>
using namespace std;

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};

ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) {
    if(pHead1 == nullptr || pHead2 == nullptr) return nullptr;
    int Length1 = 0;
    int Length2 = 0;
    ListNode* pNode1 = pHead1;
    ListNode* pNode2 = pHead2;
    while(pNode1 != nullptr) {
        Length1++;
        pNode1 = pNode1->next;
    }
    while(pNode2 != nullptr) {
        Length2++;
        pNode2 = pNode2->next;
    }
    pNode1 = pHead1;
    pNode2 = pHead2;
    while(Length1 > Length2) {
        Length1--;
        pNode1 = pNode1->next;
    }
    while(Length1 < Length2) {
        Length2--;
        pNode2 = pNode2->next;
    }
    while(pNode1 != pNode2) {
        pNode1 = pNode1->next;
        pNode2 = pNode2->next;
    }
    return pNode1;
}