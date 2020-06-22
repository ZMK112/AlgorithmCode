#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h> 
#include <queue>
#include <stack>
using namespace std;

vector<int> res;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* buildTree(TreeNode*& p, vector<int>& nums, int lens, int i)
{   
    if (i >= lens)
    {
        return p;
    }
    p = new TreeNode(nums[i]);
    buildTree(p->left, nums, lens, i * 2 + 1);
    buildTree(p->right, nums, lens, i * 2 + 2);
    return p;
}

TreeNode* createTree(TreeNode* p, vector<int>& nums)
{
    p = buildTree(p, nums, nums.size(), 0);
    return p;
}

vector<int> preorderTraversal2(TreeNode* p) {
    if (p == nullptr){
        return res;
    }
    res.push_back(p->val);
    preorderTraversal2(p->left);
    preorderTraversal2(p->right);
}

vector<int> preorderTraversal(TreeNode* root)
{
    stack<TreeNode*> stacks;
    TreeNode* p = root;
    while (p != nullptr || !stacks.empty())
    {
        while(p != nullptr){
            stacks.push(p);
            res.push_back(p->val);
            p = p->left;
        }

        if (!stacks.empty())
        {
            p = stacks.top();
            stacks.pop();
            p = p->right;
        }
    }
    return res;
}

vector<int> inorderTraversal2(TreeNode* root) {
    if (root == nullptr)
    {
        return res;
    }
    inorderTraversal2(root->left);
    res.push_back(root->val);
    inorderTraversal2(root->right);
    return res;
}

vector<int> inorderTraversal(TreeNode* root){
    if (root == nullptr)
    {
        return res;
    }
    stack<TreeNode*> stack;
    TreeNode* p = root;
    while (p != nullptr || !stack.empty())
    {
        while (p != nullptr)
        {
            stack.push(p);
            p = p->left;
        }
        if (!stack.empty())
        {

            res.push_back(stack.top()->val);
            stack.pop();
            p = p->right;
        }
    }
    return res;
}

vector<int> postorderTraversal2(TreeNode* root) {
    if (root == nullptr)
    {
        return res;
    }
    postorderTraversal2(root->left);
    postorderTraversal2(root->right);
    res.push_back(root->val);
    return res;
}

vector<int> postorderTraversal3(TreeNode* root)
{
    stack<TreeNode*> stack;
    TreeNode *p = root, *q = nullptr;
    while (p != nullptr || !stack.empty())
    {
        while (p != nullptr)
        {
            stack.push(p);
            p = p->left;
        }

        p = stack.top();

        if(p->right == q || p->right == nullptr)
        {
            stack.pop();
            res.push_back(p->val);
            q = p;
            p = nullptr;
        }
        else
        {
            p = p->right;
        }
    }
    return res;
}

// 后序遍历：左右根
// 前序遍历：根左右

vector<int> postorderTraversal(TreeNode* root)
{
    stack<TreeNode*> stack;
    TreeNode *p =root;
    while (p || !stack.empty())
    {
        while (p)
        {
            res.push_back(p->val);
            stack.push(p);
            p = p->right;
        }
        if (!stack.empty())
        {   
            p = stack.top();
            stack.pop();
            p = p->left;
        }
    }
}

int main()
{
    vector<int> nums;
    int arr[11] = {0,1,2,3,4,NULL,6,NULL,NULL,9,10};
    for (int i = 0; i < 11; i++)
    {
        nums.push_back(arr[i]);
    }

    TreeNode* root = createTree(root, nums);
    postorderTraversal3(root);

    // preorderTraversal(root);

    // stack<TreeNode> BtStack;
    // bool a = !BtStack.empty();
    // cout<< a;
    return 0;
}