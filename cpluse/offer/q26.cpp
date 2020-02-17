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

bool judgeSubtree(TreeNode* pRoot1, TreeNode* pRoot2){
    if(pRoot2 == nullptr) return true;
    if(pRoot1 == nullptr) return false;
    if(pRoot1->val == pRoot2->val) {
        return judgeSubtree(pRoot1->left, pRoot2->left) && judgeSubtree(pRoot1->right, pRoot2->right);
    }else {
        return false;
    }
}

bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
{
    bool result = false;
    if(pRoot2 == nullptr) return false;
    if(pRoot1 != nullptr && pRoot2 != nullptr) {
        if(pRoot1->val == pRoot2->val) {
            result = judgeSubtree(pRoot1, pRoot2);
        }
        if(!result) {
            result = judgeSubtree(pRoot1->left, pRoot2);
        }
        if(!result) {
            result = judgeSubtree(pRoot1->right, pRoot2);
        }
    }
    return result;
}