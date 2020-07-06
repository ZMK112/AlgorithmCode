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

ListNode *detectCycle(ListNode *head) {
    ListNode *fast = head, *slow = head, *meet;
    while (fast)
    {
        fast = fast->next;
        slow = slow->next;
        
        if(!fast)
        return nullptr;

        fast = fast->next;
        
        if (fast == slow)
        {
            meet = fast;
            break;
        }
    }
    
    while (meet != head)
    {
        if (meet == head)
        {
            return head;
        }

        meet = meet->next;
        head = head->next;
    }
    return nullptr;
}