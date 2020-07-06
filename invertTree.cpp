#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* invertTree(TreeNode* root) {
    if (!root)
    {
        return root;
    }
    TreeNode* p = root;
    TreeNode* tmp = p->left;
    p->left = p->right;
    p->right = tmp;
    // if (p->left && p->right)
    // {
    //     swap(p->left,p->right);
    // }
    // else if (p->left)
    // {
    //     p->right = p->left;
    // }
    // else
    // {
    //     p->left = p->right;
    // }
    if (p->left)
    {
        invertTree(p->left);
    }

    if (p->right)
    {
        invertTree(p->right);
    }
    return root;
}

TreeNode* invertTree(TreeNode* root) {
    stack<TreeNode*> stack;
    TreeNode* p = root;
    if (root)
    {
        return root;
    }
    stack.push(root);
    while (!stack.empty())
    {
        p = stack.top();
        stack.pop();
        TreeNode* tmp = p->left;
        p->left = p->right;
        p->right = tmp;
        if (p->left)
        {
            stack.push(p->left);
        }
        if(p->right)
        {
            stack.push(p->right);
        }
    }
    return root;
}