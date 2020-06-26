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

vector<int> res;
vector<int> rightSideView(TreeNode* root) {
    if (!root)
    {
        return res;
    }
    queue<pair<TreeNode*, int>> Q;
    Q.push({root, 0});

    while (!Q.empty())
    {
        TreeNode* tmp = Q.front().first;
        int dep = Q.front().second;
        Q.pop();

        if (dep == res.size())
        {
            res.push_back(tmp->val);
        }
        else
        {
            res[dep] = tmp->val;
        }
        
        if (tmp->left)
        {
            Q.push({tmp->left, dep + 1});
        }
        if (tmp->right)
        {
            Q.push({tmp->right, dep + 1});
        }
    }
    
    return res;
}