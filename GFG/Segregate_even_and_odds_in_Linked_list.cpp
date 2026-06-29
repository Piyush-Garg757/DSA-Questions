/*Segregate Evens and Odds in a Linked List

Given a link list, modify the list such that all the even numbers appear before all the odd numbers in the modified list. The order of appearance of numbers within each segregation should be the same as that in the original list.
NOTE: Don't create a new linked list, instead rearrange the provided one.

Examples:

Input: Linked list: 17->15->8->9->2->4->6
Output: 8->2->4->6->17->15->9
Explaination: 8,2,4,6 are the even numbers so they appear first and 17,15,9 are odd numbers that appear later.

Input: Linked List: 1 -> 3 -> 5 -> 7
Output: 1->3->5->7
Explaination: There is no even number. So no need for modification.*/

/* Structure of a link list node
class Node {
    public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};
*/

class Solution
{
public:
    Node *divide(Node *head)
    {
        // code here
        if (!head || !head->next)
            return head;
        int e_c = 0, o_c = 0;
        Node *evenhead = nullptr;
        Node *oddhead = nullptr;
        Node *temp = head;
        Node *eventemp = nullptr;
        Node *oddtemp = nullptr;
        while (temp)
        {
            if (temp->data % 2 == 0)
            {
                if (e_c == 0)
                {
                    evenhead = temp;
                    e_c++;
                }
                else
                {
                    eventemp->next = temp;
                }
                eventemp = temp;
            }
            else
            {
                if (o_c == 0)
                {
                    oddhead = temp;
                    o_c++;
                }
                else
                {
                    oddtemp->next = temp;
                }
                oddtemp = temp;
            }
            temp = temp->next;
        }
        oddtemp->next = nullptr;
        if (!evenhead)
            return oddhead;
        if (!oddhead)
            return evenhead;
        eventemp->next = oddhead;
        return evenhead;
    }
};
// TC - O(n)  SC - O(1)