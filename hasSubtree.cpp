#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

bool hasTree(TreeNode* a, TreeNode* b)
{
    if (b == nullptr)
    {
        return true; 
    }
    if (a == nullptr)
    {
        return false;
    }
    if (!(a->val == b->val))
    {
        return false;
    }
    return hasTree(a->left, b->left) && hasTree(a->right, b->right);
}


bool isSubStructure(TreeNode* A, TreeNode* B) {
    bool res = false;
    if (A != nullptr && B != nullptr)
    {
        if (A->val == B->val)
        {
            res = hasTree(A, B);
        }
        if (!res)
        {
            res = isSubStructure(A->left, B);
        }
        if (!res)
        {
            res = isSubStructure(A->right, B);
        }
    }
    return res;
}

