#include<iostream>
#include<vector>
#include<deque>
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
    deque<TreeNode*> que;
    vector<vector<int> > result;
    vector<int> level;
    int level_num = 1;
    int next_num = 0;

    if(pRoot == nullptr) return result;
    que.push_back(pRoot);
    while(!que.empty()) {
        TreeNode* temp = que.front();
        level.push_back(temp->val);
        que.pop_front();
        level_num--;
        if(temp->left) {
            que.push_back(temp->left);
            next_num++;
        }
        if(temp->right) {
            que.push_back(temp->right);
            next_num++;
        }
        if(level_num == 0) {
            level_num = next_num;
            next_num = 0;
            result.push_back(level);
            level.clear();
        }
    }
    return result;
}