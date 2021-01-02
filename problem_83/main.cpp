#include <iostream>
#include <set>
using namespace std;

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
private:
    void _clear(ListNode *node)
    {
        if (node == nullptr)
        {
            return;
        }

        _clear(node->next);
        delete node;
    }

public:
    // delete duplicate elements from the list
    ListNode *deleteDuplicates(ListNode *head)
    {
        ListNode *curr{head};
        ListNode *prev{nullptr};
        set<int> unique_elements;

        while (curr != nullptr)
        {
            // remove element if it's in the set
            if (unique_elements.count(curr->val) == 1)
            {
                prev->next = curr->next;
                delete curr;
                curr = prev->next;
                continue;
            }

            unique_elements.emplace(curr->val);
            prev = curr;
            curr = curr->next;
        }

        return head;
    }

    // print all elements in the list
    void printList(ListNode *list)
    {
        ListNode *curr{list};

        if (curr == nullptr)
        {
            return;
        }

        while (curr->next != nullptr)
        {
            cout << curr->val << "->";
            curr = curr->next;
        }
        cout << curr->val << endl;
    }

    // remove all elements from the list
    void clear(ListNode *list)
    {
        _clear(list);
    }
};

int main()
{
    Solution a;
    ListNode *node1{new ListNode(1)};
    ListNode *node2{new ListNode(1)};
    ListNode *node3{new ListNode(2)};
    ListNode *node4;
    ListNode *node5;

    node1->next = node2;
    node2->next = node3;
    cout << "Input: ";
    a.printList(node1);
    cout << "Output: ";
    a.printList(a.deleteDuplicates(node1));
    a.clear(node1);

    node1 = new ListNode(1);
    node2 = new ListNode(1);
    node3 = new ListNode(2);
    node4 = new ListNode(3);
    node5 = new ListNode(3);

    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    cout << "Input: ";
    a.printList(node1);
    cout << "Output: ";
    a.printList(a.deleteDuplicates(node1));
    a.clear(node1);

    return 0;
}
