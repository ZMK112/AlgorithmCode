struct ListNode {
//     int val;
//     ListNode *next;
//     ListNode(int x) : val(x), next(NULL) {}
// };

// ListNode* reverseList(ListNode* head) {
//     stack<ListNode*> stacks;
//     ListNode* p = head;
//     while (p)
//     {
//         stacks.push(p);
//         p = p->next;
//     }

//     head = stacks.top();
//     stacks.pop();
//     ListNode* tmp;
//     // head->next = tmp;
//     while (!stacks.empty())
//     {
//         if (tmp->next == nullptr)
//         {
//             head->next = stacks.top();
//             tmp = head->next;
//         }
//         else
//         {
//             tmp->next = stacks.top();
//             tmp = tmp->next;
//         }
//         stacks.pop();
//     }
// }