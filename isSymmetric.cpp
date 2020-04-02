#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/* bool symmetric(TreeNode* a, TreeNode* b)
{
    if (a == nullptr && b == nullptr)
    {
        return true;
    }

    if (a == nullptr || b == nullptr)
    {
        return false;
    }
    
    if (a->val != b->val)
    {
        return false;
    }
    
    return symmetric(a->left, b->right) && symmetric(a->right, b->left);
} */

bool isSymmetric(TreeNode* a, TreeNode* b)
{
    stack<TreeNode*> s1;
    stack<TreeNode*> s2;
    s1.push(a);
    s2.push(b);

    bool res = false;

    while (!s1.empty() && !s2.empty())
    {
        TreeNode* one = s1.top();
        s1.pop();
        TreeNode* two = s2.top();
        s2.pop();

        if (one->val != two->val)
        {
            res = false;
            return res;
        }

        s1.push(a->left);
        s1.push(a->right);
        s2.push(b->right);
        s2.push(b->left);
    }

    res = s1.empty() && s2.empty();
    return res;
}

bool isSymmetric(TreeNode* root) 
{
    return symmetric(root, root);
}