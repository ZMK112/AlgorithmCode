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

vector<vector<int>> res;
void preorder(TreeNode* root, int pathVal, vector<int> path, int sum)
{
    if(!root) return;

    pathVal += root->val;
    path.push_back(root->val);

    if (!root->left && !root->right && pathVal == sum)
    {
        res.push_back(path);
    }

    preorder(root->left, pathVal, path, sum);
    preorder(root->right, pathVal, path, sum);

    pathVal -= root->val;
    path.pop_back();
    
}

vector<vector<int>> pathSum(TreeNode* root, int sum) {
    vector<int> path;
    preorder(root, 0, path, sum);
    return res;
}