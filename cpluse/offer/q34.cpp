#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};

static bool cmp(vector<int> a, vector<int>b) {
    return a.size() > b.size();
}

void FindPathCore(TreeNode* root, vector<int> path, vector<vector<int> > &result, int expectNumber, int sum) {
    path.push_back(root->val);
    if(sum + root->val == expectNumber && !root->left && !root->right) {
        result.push_back(path);
    }
    if(root->left) {
        FindPathCore(root->left, path, result, expectNumber, sum + root->val);
    }
    if(root->right) {
        FindPathCore(root->right, path, result, expectNumber, sum + root->val);
    }
}

vector<vector<int> > FindPath(TreeNode* root,int expectNumber) {
    vector<int> path;
    vector<vector<int> > result;
    if(root == nullptr) return result;
    FindPathCore(root, path, result, expectNumber, 0);
    sort(result.begin(), result.end(), cmp);
    return result;
}

int main(void) {
    vector<int> path;
    vector<vector<int> > result;

    path.push_back(1);
    result.push_back(path);
    path.push_back(2);
    result.push_back(path);
    sort(result.begin(), result.end(), cmp);
    cout<<result[0][1]<<endl;
}