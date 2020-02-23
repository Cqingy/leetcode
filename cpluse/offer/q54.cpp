#include<iostream>
#include<vector>
using namespace std;

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};

TreeNode* FindKthNode(TreeNode* pRoot, int &k) {
    TreeNode* target = nullptr;
    if(pRoot->left != nullptr) target = FindKthNode(pRoot->left, k);
    if(target == nullptr) {
        if(k == 1)return pRoot;
        else k--;
    }
    if(target == nullptr && pRoot->right != nullptr) {
        target = FindKthNode(pRoot->right, k);
    }
    return target;
}

TreeNode* KthNode(TreeNode* pRoot, int k)
{
    if(pRoot == nullptr || k <= 0) return nullptr;
    return FindKthNode(pRoot, k);
}

int main(void) {
    return 0;
}