#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <deque>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void buildTree(TreeNode* &root, int* nums, int lens, int i)
{
    if (i >= lens)
    {
        return;
    }
    root = new TreeNode(nums[i]);
    buildTree(root->left, nums, lens, 2 * i + 1);
    buildTree(root->right, nums, lens, 2 * i + 2);
}

vector<int> levelOrder(TreeNode* root) {
    vector<int> res;
    if (!root)
    {
        return res;
    }
    deque<TreeNode*> dequeNode;
    dequeNode.push_back(root);
    while (dequeNode.size())
    {
        TreeNode * pNode = dequeNode.front();
        dequeNode.pop_front();
        res.push_back(pNode->val);
        if (pNode->left)
        {
            dequeNode.push_back(pNode->left);
        }
        if (pNode->right)
        {
            dequeNode.push_back(pNode->right);
        }
    }
    return res;
}

vector<vector<int>> levelOrder2(TreeNode* root) {
    vector<vector<int>> res;
    if (root == nullptr)
    {
        return res;
    }
    int cur = 0;
    int next = 0;
    stack<TreeNode*> nodes[2];
    nodes[cur].push(root);
    vector<int> node;
    while (!nodes[0].empty() || !nodes[1].empty())
    {   
        TreeNode* pNode = nodes[cur].top();
        nodes[cur].pop();
        node.push_back(pNode->val);

        if (cur == 0)
        {
            if (pNode->left != nullptr)
            {
                nodes[next].push(pNode->left);
            }
            if (pNode->right != nullptr)
            {
                nodes[next].push(pNode->right);
            }
        }
        else{
            if (pNode->right != nullptr)
            {
                nodes[next].push(pNode->right);
            }
            if (pNode->left != nullptr)
            {
                nodes[next].push(pNode->left);
            }
        }
        if (nodes[cur].empty())
        {  
            cur = 1 - cur;
            next = 1 - next;
            res.push_back(node);
            node.clear();
        }
    }
    return res;
}

int main()
{
    int nums[7] = {3,9,20,NULL,NULL,15,7};
    TreeNode* root;
    buildTree(root, nums, 7, 0);
    vector<vector<int>> res = levelOrder2(root);
    return 0;
}