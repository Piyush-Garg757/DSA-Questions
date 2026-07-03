/*Reverse Linked List II

Given the head of a singly linked list and two integers left and right where left <= right, reverse the nodes of the list from position left to position right, and return the reversed list.

Example 1:
Input: head = [1,2,3,4,5], left = 2, right = 4
Output: [1,4,3,2,5]

Example 2:
Input: head = [5], left = 1, right = 1
Output: [5]*/

// Optimal but it is done in two passes
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    ListNode *reverseList(ListNode *head)
    {
        ListNode *prev = nullptr;
        ListNode *curr = head;
        while (curr)
        {
            ListNode *nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }
        return prev;
    }
    ListNode *reverseBetween(ListNode *head, int left, int right)
    {
        if (!head || !head->next)
            return head;
        ListNode *l = head;
        ListNode *r = head;
        ListNode *temp = head;
        ListNode *dummy = new ListNode(-1);
        ListNode *dummytemp = dummy;
        ListNode *nxt = nullptr;
        dummytemp->next = temp;
        int cnt = 0;
        while (dummytemp)
        {
            if (cnt + 1 == left)
            {
                temp = dummytemp->next;
                l = dummytemp;
            }
            else if (cnt == right)
            {
                r = dummytemp;
                nxt = dummytemp->next;
                dummytemp->next = nullptr;
                break;
            }
            dummytemp = dummytemp->next;
            cnt++;
        }
        l->next = reverseList(l->next);
        temp->next = nxt;
        return dummy->next;
    }
};
// TC - O(n)  SC - O(1) 