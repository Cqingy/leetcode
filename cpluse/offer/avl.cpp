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

bool dep_avl(TreeNode* pRoot, int &depth) {
    if(pRoot == nullptr) {
        depth = 0;
        return true;
    }
    int left, right;
    if(dep_avl(pRoot->left, left) && dep_avl(pRoot->right, right)) {
        int diff = left - right;
        if(diff >= -1 && diff <= 1) {
            depth = (left > right) ? (left + 1) : (right + 1);
            return true;
        }
    }
    return false;
}

bool IsBalanced_Solution(TreeNode* pRoot) {
    int depth = 0;
    return dep_avl(pRoot, depth);
}