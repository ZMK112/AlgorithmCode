#include <iostream>
#include <fstream>
#include<sstream>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

string serialize(TreeNode* root)
{
    ostringstream out;
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty())
    {
        TreeNode* tmp = q.front();
        q.pop();
        if(tmp)
        {
            out<< tmp->val << " ";
            q.push(tmp->left);
            q.push(tmp->right);
        }
        else
        {
            out<< "null ";
        }
    }
    return out.str();
}

TreeNode* deserialize(string data)
{
    istringstream input(data);
    string val;
    vector<TreeNode*> res;
    while (input >> val)
    {
        if(val == "null")
        {
            res.push_back(nullptr);
        }
        else
        {
            res.push_back(new TreeNode(stoi(val)));
        }
    }
    
    int j = 1;
    for (int i = 0; j < res.size(); ++i)
    {
        if (res[i] == nullptr)
        {
            continue;
        }
        if (j < res.size())
        {
            res[i]->left = res[j++];
        }
        if (j < res.size())
        {
            res[i]->right = res[j++];
        }
    }
    return res[0];
}

vector<int> res;

    vector<int> countSmaller(vector<int>& vec) {

        if (vec.empty()){
            return {};
        }

        vector<pair<int, int>> nums;
        for (int i = 0; i < vec.size(); i++){
            nums.emplace_back(vec[i], i);
        }

        res = vector<int>(vec.size(), 0);
        merge_sort(nums, 0, (int)nums.size() - 1);

        return res;
    }

    void merge_sort(vector<pair<int, int>>& nums, int left, int right){
        if (left < right){
            int mid = left + (right - left) / 2;

            merge_sort(nums, left, mid);
            merge_sort(nums, mid + 1, right);
            merge(nums, left, mid, right);
        }
    }

    void merge(vector<pair<int, int>>& nums, int left, int mid, int right){
        int i = left, j = mid + 1;
        int k = left;

        vector<pair<int, int>> sort_nums;

        while (i <= mid && j <= right){
            if (nums[i].first <= nums[j].first){
                res[nums[i].second] += j - mid - 1;
                sort_nums.push_back(nums[i++]);
            }else if (nums[i].first > nums[j].first){
                sort_nums.push_back(nums[j++]);
            }
        }

        while (i <= mid){
            res[nums[i].second] += j - mid - 1;
            sort_nums.push_back(nums[i++]);
        }

        while (j <= right){
            sort_nums.push_back(nums[j++]);
        }

        for (int m = 0, n = left; m < sort_nums.size(); m++, n++){
            nums[n] = sort_nums[m];
        }
    }