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

TreeNode* recoverFromPreorder(string S) {
    int depth = 0;
    vector<TreeNode*> nodes(S.size());
    nodes[0] = new TreeNode(stoi(S.substr(0)));
    for (int i = 0; i < S.size(); i++)
    {
        if (S[i] == '-')
        {
            depth++;
        }
        else if (depth > 0)
        {
            TreeNode* node = new TreeNode(stoi(S.substr(i)));
            if (nodes[depth - 1]->left == nullptr)
            {
                nodes[depth - 1]->left = node;
            }
            else
            {
                nodes[depth - 1]->right = node;
            }
            nodes[depth] = node;
            depth = 0;
        }
    }
    return nodes[0];
}