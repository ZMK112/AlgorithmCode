#include <iostream>
#include <vector>
using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    if (l1 == nullptr)
    {
        return l2;
    }
    if (l2 == nullptr)
    {
        return l1;
    }

    ListNode* p_merge;
    if (l1->val <= l2->val)
    {
        p_merge = l1;
        p_merge->next = mergeTwoLists(l1->next,l2);
    }
    else
    {
        p_merge = l2;
        p_merge->next = mergeTwoLists(l1, l2->next);
    }
    return p_merge;
}

ListNode* create_node(ListNode*& head, vector<int>& nums)
{
    head = new ListNode(0);
    ListNode* p = head;
    for (int i = 0; i < nums.size(); i++)
    {
        ListNode* p2 = new ListNode(nums[i]);
        p->next = p2;
        p = p2;
    }
    return head;
}

int main()
{
    vector<int> nums = {1,2,4};
    vector<int> num2 = {1,3,4};
    ListNode* p1 = create_node(p1, nums);
    ListNode* p2 = create_node(p2, nums);
    ListNode* p3 = mergeTwoLists(p1,p2);
    return 0;
}