#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

void cloneNodes(Node* head)
{
    Node* point = head;
    while (point != nullptr)
    {
        Node* clonePoint = new Node(point->val);
        clonePoint->next = point->next;
        clonePoint->random = nullptr;
        point->next = clonePoint;
        point = clonePoint->next;
    }
}

void connection(Node* head)
{
    Node* point = head;
    while (point != nullptr)
    {
        Node* clonePoint = point->next;
        if (point->random != nullptr)
        {
            clonePoint->random = point->random->next;
        }
        point = clonePoint->next;
    }
}

Node* reconnection(Node* head) {
    Node* point = head;
    Node* cloneHead = nullptr;
    Node* cloneNode = nullptr;

    if (point != nullptr)
    {
        cloneHead = cloneNode = point->next;
        point->next = cloneNode->next;
        point = point->next;
    }
    while (point != nullptr)
    {
        cloneNode->next = point->next;
        cloneNode = cloneNode->next;
        point->next = cloneNode->next;
        point = point->next;
    }
    return cloneHead;
}

Node* copyRandomList(Node* head) {
    cloneNodes(head);
    connection(head);
    return reconnection(head);
}