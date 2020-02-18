#include<iostream>
using namespace std;

struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
            label(x), next(NULL), random(NULL) {
    }
};

void CloneList(RandomListNode* pHead) {
    while(pHead != nullptr) {
        RandomListNode* tempNode = new RandomListNode(pHead->label);
        tempNode->next = pHead->next;
        pHead->next = tempNode;
        pHead = tempNode->next;
    }
}

void LinkRandom(RandomListNode* pHead) {
    while(pHead != nullptr) {
        if(pHead->random) pHead->next->random = pHead->random->next;
        pHead = pHead->next->next;
    }
}

RandomListNode* Reconnect(RandomListNode* pHead) {
    RandomListNode* result = new RandomListNode(-1);
    RandomListNode* pNode = result;
    if(pHead == nullptr) return result->next;
    // 拆分部分可以更加优化
    while(pHead != nullptr && pHead->next->next != nullptr) {
        RandomListNode* tempNode = pHead->next->next;
        pHead->next->next = tempNode->next;
        pNode->next = pHead->next;
        pNode = pNode->next;
        pHead->next = tempNode;
        pHead = pHead->next;
    }
    pNode->next = pHead->next;
    pHead->next = nullptr;
    return result->next;
}

RandomListNode* Clone(RandomListNode* pHead)
{
    CloneList(pHead);
    LinkRandom(pHead);
    return Reconnect(pHead);
}

int main(void) {
    RandomListNode* pHead = new RandomListNode(1);
    RandomListNode* pNode = new RandomListNode(-1);
    int n;

    cin>>n;
    for(int i = 0; i < n; i++) {
        int temp;
        cin>>temp;
        RandomListNode* tempNode = new RandomListNode(temp);
        pNode->next = tempNode;
        pNode = pNode->next;
    }
    pHead = Clone(pHead);
}