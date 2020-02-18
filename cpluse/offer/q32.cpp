#include<iostream>
#include<deque>
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

vector<int> PrintFromTopToBottom(TreeNode* root) {
    vector<int> result;
    deque<TreeNode*> q;
    if(root == nullptr) return result;
    q.push_back(root);
    while(!q.empty()) {
        TreeNode* temp = q.front();
        result.push_back(temp->val);
        q.pop_front();
        if(temp->left) q.push_back(temp->left);
        if(temp->right) q.push_back(temp->right);
    }
    return result;
}

int main(void) {
    return 0;
}