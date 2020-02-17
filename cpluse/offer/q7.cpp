#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
    if(pre.size() <= 0 || vin.size() <= 0)return NULL;
    TreeNode* root = new TreeNode(pre[0]);
    // if(pre.size() == 1 || vin.size() == 1){
    //     return root;
    // }
    int num = 0;
    for(int i = 0; i < vin.size(); i++){
        if(vin[i] == root->val){
            num = i;
            break;
        }
    }
    vector<int> prel, prer, inl, inr;
    for(int i = 0; i < num; i++){
        prel.push_back(pre[i + 1]);
        inl.push_back(vin[i]);
    }
    for(int i = num + 1; i < pre.size(); i++){
        prer.push_back(pre[i]);
        inr.push_back(vin[i]);
    }
    root->left = reConstructBinaryTree(prel, inl);
    root->right = reConstructBinaryTree(prer, inr);
    return root;
}

int main(void) {
    vector<int> a;
    for(int i = 0; i < 10; i++){
        a.push_back(i);
    }
    vector<int> b(a.begin() + 1, a.begin() + 3);
    for(int i = 0; i < b.size(); i++){
        cout<<b[i]<<endl;
    }
}