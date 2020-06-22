#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <unordered_map>
#include <queue>
#include <algorithm>
using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* reverseList(ListNode* head) {
    stack<int> stacks;
    ListNode* p = head;
    
    while (p->next)
    {
        stacks.push(p->val);
        p = p->next;
    }
    
    ListNode *tmp;
    tmp = head;
    while (!stacks.empty())
    {
        tmp->next = new ListNode(stacks.top());
        stacks.pop();
        tmp = tmp->next;
    
    }
    return head;
}


ListNode* reverseList(ListNode* head) {
    ListNode* new_head = nullptr;
    while (head)
    {
        ListNode *next = head->next;
        head->next = new_head;
        new_head = head;
        head = next;
    }
    return new_head;
}

int main()
{
    ListNode *root, *p;
    vector<int> nums = {1,2,3,4,5};
    root = new ListNode(nums[0]);
    p = root;
    for (int i = 1; i < nums.size(); i++)
    {
        ListNode* tmp = new ListNode(nums[i]);
        p->next = tmp;
        p = p->next;
    }
    reverseList(root);
    return 0;
}