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

void preorder(TreeNode* root, TreeNode* aim, vector<TreeNode*>& path, vector<TreeNode*>& res, int flag)
{
    if (!root || flag)
    {
        return;
    }

    path.push_back(root);
    
    if (root == aim)
    {
        flag = 1;
        res = path;
    }

    preorder(root->left, aim, path, res, flag);
    preorder(root->right, aim, path, res, flag);
    path.pop_back();
}

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    vector<TreeNode*> p_path;
    vector<TreeNode*> q_path;
    vector<TreeNode*> tmp_path;
    TreeNode* res;

    preorder(root, p, tmp_path, p_path, 0);
    tmp_path.clear();
    preorder(root, q, tmp_path, q_path, 0);

    int lens = p_path.size() < q_path.size() ? p_path.size() : q_path.size();
    
    for (int i = 0; i < lens; i++)
    {
        if (p_path[i] == q_path[i])
        {
            res = p_path[i];
        }
    }
    return res;
}