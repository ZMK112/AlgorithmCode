#include <iostream>
#include <vector>
using namespace std;

 struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* deleteNode(ListNode* head, int val) {
    ListNode* p = new ListNode(-1);
    p = head;

    if (p == nullptr)
    {
        return head;
    }
    if (p->val == val)
    {
        return nullptr;
    }
    
    while (p->next != nullptr && p->next->val != val)
    {
        p = p->next;
    }
    if (p->next->next != nullptr)
    {
       p->next = p->next->next;
    }
    else
    {
        p->next = nullptr;
    }
    
    return head;
}

ListNode* createNode(ListNode* head, vector<int>& nums)
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
    vector<int> nums = {4,5,1,9};
    ListNode* p;
    p = createNode(p, nums);
    deleteNode(p, 1);
    return 0;
}
