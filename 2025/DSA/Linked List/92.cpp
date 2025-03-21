#include <bits/stdc++.h>
using namespace std;

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
public:
    ListNode *reverseList(ListNode *head, int left, int right)
    {
        /*
        Detailed Steps:
        1.First, use a dummy node that points to the head of the list to handle edge cases where the reversal starts at the head.
        2. Then, iterate to the node just before the left-th node.
        3.Start the reversal from the left-th node and adjust the next pointers for the nodes between left and right.
        4.Finally, return the list starting from dummy->next since the head might have changed.
        */

        // If the list is empty or left is equal to right,
        // then no reversal is needed, and we can return the list as is
        if (!head || left == right)
            return head;

        ListNode *temp = new ListNode(0);
        temp->next = head;
        ListNode *prev = temp;

        // Find the node before the left-th node
        for (int i = 1; i < left; ++i)
        {
            prev = prev->next;
        }

        ListNode *curr = prev->next;
        ListNode *next = curr->next;

        // Reverse the sublist
        // Reattach the reversed sublist
        for (int i = 0; i < right - left; ++i)
        {
            curr->next = next->next;
            next->next = prev->next;
            prev->next = next;
            next = curr->next;
        }

        return temp->next;
    }
};

int main()
{
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    Solution s;

    head = s.reverseList(head, 2, 4);

    while (head != nullptr)
    {
        cout << head->val << " ";
        head = head->next;
    }

    return 0;
}