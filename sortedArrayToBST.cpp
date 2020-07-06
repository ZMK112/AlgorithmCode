#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <unordered_map>
#include <queue>
#include <algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void buildTree(vector<int>& nums, TreeNode*& root, int lens, int index)
{
    if (index >= lens)
    {
        return;
    }
    root = new TreeNode(nums[index]);
    buildTree(nums, root->left, lens, index * 2 + 1);
    buildTree(nums, root->right, lens, index * 2 + 2);
}

TreeNode* createTree(vector<int>& nums, TreeNode*& root, int left, int right)
{
    if (left > right)
    {
        return nullptr;
    }

    int mid = (left + right) / 2;
    root = new TreeNode(nums[mid]);
    root->left = createTree(nums, root, left, mid - 1);
    root->right = createTree(nums, root, mid + 1, right);
    return root;
}

TreeNode* sortedArrayToBST(vector<int>& nums) {
    if (nums.empty())
    {
        return nullptr;
    }

    TreeNode* root;
    root = createTree(nums, root, 0, nums.size() - 1);
    return root;
}