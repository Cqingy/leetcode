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

vector<char> buff;

void dfs(TreeNode *root) {
    if(root == nullptr) {
        buff.push_back('#');
        return;
    }
    buff.push_back(root->val + '0');
    dfs(root->left);
    dfs(root->right);
}

TreeNode* dfs2(char* &str) {
    if(str == nullptr || *str == '\0') {
        return nullptr;
    }
    if(*str == '#') {
        str++;
        return nullptr;
    }
    TreeNode* temp = new TreeNode(*str - '0');
    str++;
    temp->left = dfs2(str);
    temp->right = dfs2(str);
    return temp;
}

char* Serialize(TreeNode *root) {    
    if(root == nullptr) return nullptr;
    dfs(root);
    char* result = new char[buff.size()];
    for(int i = 0; i < buff.size(); i++) result[i] = buff[i];
    return result;
}

TreeNode* Deserialize(char *str) {
    TreeNode* result;
    return dfs2(str);
}

int main(void) {
    int a = 5;
    char b = a + '0';
    char d[] = "12#3##4##";

    TreeNode* temp;
    // cout<<*d - '0'<<endl;
    temp = Deserialize(d);

    cout<<Serialize(temp)<<endl;
}