#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct TreeLinkNode {
    int val;
    struct TreeLinkNode *left;
    struct TreeLinkNode *right;
    struct TreeLinkNode *next;
    TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {
        
    }
};

TreeLinkNode* GetNext(TreeLinkNode* pNode) {
    if(pNode->right != NULL){
        TreeLinkNode* temp = pNode->right;
        while(temp->left != NULL){
            temp = temp->left;
        }
        return temp;
    }
    TreeLinkNode* parent = pNode->next;
    TreeLinkNode* currNode = pNode;
    while(parent != NULL && parent->right == currNode){
        currNode = parent;
        parent = parent->next;
    }
    return parent;
}

