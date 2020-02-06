#include<iostream>
#include<algorithm>
#include<vector>

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
};

void inorder(TreeNode* root){
    if(root == nullptr)return;
    if(root->left)inorder(root->left);
    std::cout<<root->val<<' ';
    if(root->right)inorder(root->right);
}

void preorder(TreeNode* root){
    if(root == nullptr)return;
    std::cout<<root->val<<' ';
    if(root->left)preorder(root->left);
    if(root->right)preorder(root->right);
}

void postorder(TreeNode* root){
    if(root == nullptr)return;
    if(root->left)postorder(root->left);
    if(root->right)postorder(root->right);
    std::cout<<root->val<<' ';
}

bool FindNode(TreeNode* root, int val){
    if(root == nullptr)return false;
    if(val > root->val){
        return FindNode(root->right, val);
    }else{
        return FindNode(root->left, val);
    }
}



int main(void){
    TreeNode* root;
    // std::cin>>root->val;
    // std::cout<<root->val<<'\n';
    return 0;
}