#include<iostream>
using namespace std;

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};

ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
    if(pListHead == nullptr || k == 0) return nullptr;
    ListNode* fastNode = pListHead;
    ListNode* slowNode = pListHead;

    for(int i = 0; i < k; i++) {
        fastNode = fastNode->next;
        if(fastNode == nullptr && i != k-1) return nullptr;
    }
    while(fastNode != nullptr) {
        fastNode = fastNode->next;
        slowNode = slowNode->next;
    }
    return slowNode;
}

int main(void) {
    int n;
    ListNode* Head = new ListNode(-1);
    ListNode* node = Head;

    cin>>n;
    for(int i = 0; i < n; i++) {
        int temp;
        cin>>temp;
        ListNode* tempNode = new ListNode(temp);
        node->next = tempNode;
        node = node->next;
    }
    cout<<FindKthToTail(Head, 2)->val<<endl;
}