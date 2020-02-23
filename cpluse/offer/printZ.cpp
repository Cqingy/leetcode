#include<iostream>
#include<vector>
#include<stack>
using namespace std;

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};

vector<vector<int> > Print(TreeNode* pRoot) {
    vector<vector<int> > result;
    vector<int> level;
    stack<TreeNode*> left, right;
    if(pRoot == nullptr) return result;
    left.push(pRoot);
    while(!left.empty() || !right.empty()) {
        while(!left.empty()) {
            TreeNode* temp = left.top();
            level.push_back(temp->val);
            left.pop();
            if(temp->left) right.push(temp->left);
            if(temp->right) right.push(temp->right);
        }
        if(!level.empty()) {
            result.push_back(level);
            level.clear();
        }
        while(!right.empty()) {
            TreeNode* temp = right.top();
            level.push_back(temp->val);
            right.pop();
            if(temp->right) left.push(temp->right);
            if(temp->left) left.push(temp->left);
        }
        if(!level.empty()) {
            result.push_back(level);
            level.clear();
        }
    }
    return result;
}