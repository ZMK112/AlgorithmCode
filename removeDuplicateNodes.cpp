#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <unordered_map>
#include <queue>
#include <algorithm>
#include <set>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* removeDuplicateNodes(ListNode* head) {
    if (!head)
    {
        return head;
    }
    
    ListNode* p = head;
    ListNode* last;
    set<int> res;

    while (p)
    {
        if (res.count(p->val))
        {
            // auto tmp = p;
            p = p->next;
            last->next = p;
        }
        else
        {
            res.insert(p->val);
            last = p;
            p = p->next;
        }
    }
    return head;
}

/*位置不能发生改变
ListNode* removeDuplicateNodes(ListNode* head) {
    vector<int> res;
    ListNode* p = head;
    while (p)
    {
        res.push_back(head->val);
        p = p->next;
    }

    sort(res.begin(), res.end());
    set<int> tmp(res.begin(), res.end());
    vector<int> nums(tmp.begin(), tmp.end());

    for (int i = 1; i < nums.size(); i++)
    {
        p->val = nums[i];
        p = p->next;
    }
    return head;
}*/
