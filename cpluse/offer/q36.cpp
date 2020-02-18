#include<iostream>
using namespace std;

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};

void ConvertNode(TreeNode* pRootOfTree, TreeNode* &LastNodeInList) {
    if(pRootOfTree == nullptr) return;
    if(pRootOfTree->left) ConvertNode(pRootOfTree->left, LastNodeInList);
    pRootOfTree->left = LastNodeInList;
    if(LastNodeInList != nullptr) LastNodeInList->right = pRootOfTree;
    LastNodeInList = pRootOfTree;
    if(pRootOfTree->right) ConvertNode(pRootOfTree->right, LastNodeInList);
}

TreeNode* Convert(TreeNode* pRootOfTree)
{
    if(pRootOfTree == nullptr) return nullptr;
    TreeNode* LastNodeInList = nullptr;
    ConvertNode(pRootOfTree, LastNodeInList);
    while(pRootOfTree->left != nullptr) pRootOfTree = pRootOfTree->left;
    return pRootOfTree;
}

int main(void) {


}