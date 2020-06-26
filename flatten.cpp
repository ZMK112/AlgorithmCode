#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <unordered_map>
#include <queue>
#include <algorithm>
#include <map>
#include <set>
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<TreeNode*> res;

void preorder(TreeNode* root)
{
    if (!root)
    {
        return;
    }
    res.push_back(root);
    preorder(root->left);
    preorder(root->right);
}

void flatten(TreeNode* root) {
    preorder(root);
    for (int i = 1; i < res.size(); i++)
    {
        res[i - 1]->left = nullptr;
        res[i - 1]->right = res[i];
    }
    return;
}

