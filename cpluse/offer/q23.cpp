#include<iostream>
using namespace std;

struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};

ListNode* meetingNode(ListNode* pHead) {
    if(pHead == nullptr || pHead->next == nullptr) return nullptr;
    ListNode* fastNode = pHead->next->next;
    ListNode* slowNode = pHead->next;
    while(fastNode != nullptr) {
        if(fastNode == slowNode) return fastNode;
        slowNode = slowNode->next;
        fastNode = fastNode->next;
        if(fastNode != nullptr) fastNode =fastNode->next;
    }
    return nullptr;
}

ListNode* EntryNodeOfLoop(ListNode* pHead) {
    if(pHead == nullptr) return nullptr;
    ListNode* meetNode = meetingNode(pHead);
    if(meetNode == nullptr) return nullptr;
    ListNode* originNode = meetNode;
    int loopNum = 1;
    while(meetNode->next != originNode) {
        meetNode = meetNode->next;
        loopNum += 1;
    }
    ListNode* fastNode = pHead;
    ListNode* slowNode = pHead;
    for(int i = 0; i < loopNum; i++) {
        fastNode = fastNode->next;
    }
    while(fastNode != slowNode) {
        fastNode = fastNode->next;
        slowNode = slowNode->next;
    }
    return fastNode;
}

int main(void) {

}