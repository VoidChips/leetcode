#include <iostream>
#include <string>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void printList(ListNode *list)
{
    while (list != nullptr)
    {
        cout << list->val << " ";
        list = list->next;
    }
    cout << endl;
}

void deallocate(ListNode *list)
{
    while (list != nullptr)
    {
        ListNode *temp = list;
        delete temp;
        list = list->next;
    }
}

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{
    ListNode *result{nullptr};
    ListNode *node;
    ListNode *prev;
    int carry{};
    while (l1 != nullptr || l2 != nullptr || carry != 0)
    {
        int l1_val{}, l2_val{};
        if (l1 != nullptr)
        {
            l1_val = l1->val;
            l1 = l1->next;
        }
        if (l2 != nullptr)
        {
            l2_val = l2->val;
            l2 = l2->next;
        }
        int curr_sum{l1_val + l2_val + carry};

        if (curr_sum > 9)
        {
            carry = curr_sum / 10;
            curr_sum %= 10;
        }
        else
        {
            carry = 0;
        }

        if (result == nullptr)
        {
            result = new ListNode(curr_sum);
            node = result;
        }
        else
        {
            prev = node;
            node = new ListNode(curr_sum);
            prev->next = node;
        }
    }
    return result;
}

main()
{
    ListNode *n1{new ListNode(9)};
    // ListNode *n2{new ListNode(4)};
    // ListNode *n3{new ListNode(3)};
    // n1->next = n2;
    // n2->next = n3;

    ListNode *n4{new ListNode(1)};
    ListNode *n5{new ListNode(9)};
    ListNode *n6{new ListNode(9)};
    ListNode *n7{new ListNode(9)};
    ListNode *n8{new ListNode(9)};
    ListNode *n9{new ListNode(9)};
    ListNode *n10{new ListNode(9)};
    ListNode *n11{new ListNode(9)};
    ListNode *n12{new ListNode(9)};
    ListNode *n13{new ListNode(9)};
    n4->next = n5;
    n5->next = n6;
    n6->next = n7;
    n7->next = n8;
    n8->next = n9;
    n9->next = n10;
    n10->next = n11;
    n11->next = n12;
    n12->next = n13;

    ListNode *result{addTwoNumbers(n1, n4)};
    printList(result);
    deallocate(n1);
    deallocate(n4);
    deallocate(result);
}