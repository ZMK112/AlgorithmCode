#include <iostream>
#include <vector>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): val(x),left(NULL),right(NULL){}
};

void findPath(TreeNode* root, int sum, vector<vector<int>>& path, int cursum)
{
    vector<int> curpath;
    cursum += root->val;
    curpath.push_back(root->val);
    bool leaf = (root->left == nullptr) && (root->right == nullptr);
    if (cursum == sum && leaf)
    {
        path.push_back(curpath);
    }
    if (root->left != nullptr)
    {
        findPath(root->left, sum, path, cursum);
    }
    if (root->right != nullptr)
    {
        findPath(root->right, sum, path, cursum);
    }
    curpath.pop_back();
}

vector<vector<int>> pathSum(TreeNode* root, int sum) {
    vector<vector<int>> path;
    if (root == nullptr)
    {
        return path;
    }    
    int curSum = 0;
    findPath(root, sum, path, curSum);
    return path;
}

TreeNode* buildTree(TreeNode* &root, vector<int>& nums, int lens, int i)
{
    if (i >= lens)
    {
        return root;
    }
    root = new TreeNode(nums[i]);
    buildTree(root->left, nums, lens, i * 2 + 1);
    buildTree(root->right, nums, lens, i * 2 + 2);
    return root;
}

TreeNode* Trees(TreeNode* root, vector<int>& nums)
{
    int lens = nums.size();
    buildTree(root, nums, lens, 0);
    return root;
}

int main()
{   
    // vector<int> res;
    vector<int> nums = {5,4,8,11,NULL,13,4,7,2,NULL,NULL,5,1};
    TreeNode* root;
    root = Trees(root, nums);
    vector<vector<int>> res = pathSum(root, 22);
    return 0;
}
