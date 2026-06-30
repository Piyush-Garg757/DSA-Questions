/*Delete all occurrences in a doubly linked list

You are given the head of a doubly Linked List and a key x . Your task is to delete all occurrences of the given key x if it is present and return the new DLL.

Examples:
Input: 2<->2<->10<->8<->4<->2<->5<->2, x = 2
Output:  10<->8<->4<->5
Explanation:
All Occurences of 2 have been deleted.

Input: head = 9<->1<->3<->4<->5<->1<->8<->4, x = 9
Output: 1<->3<->4<->5<->1<->8<->4
Explanation:
All Occurences of 9 have been deleted.*/

/* a Node of the doubly linked list
class Node {
    public:
    int data;
    Node* next;
    Node* prev;

    Node(int x) {
        data = x;
        next = nullptr;
        prev = nullptr;
    }
};
*/

class Solution
{
public:
    // Function to delete a specified node from the linked list
    Node *deleteAllOccurOfX(Node *head, int x)
    {
        // code here
        if (!head)
            return nullptr;
        while (head != nullptr && head->data == x)
        {
            Node *temp = head;
            head = head->next;
            head->prev = nullptr;
            delete temp;
        }
        Node *temp = head;
        while (temp && temp->next)
        {
            if (temp->next->data == x)
            {
                Node *newnode = temp->next;
                temp->next = newnode->next;
                if (newnode->next != nullptr)
                {
                    newnode->next->prev = temp;
                }
                delete newnode;
                continue;
            }
            temp = temp->next;
        }
        return head;
    }
};
// TC - O(n)  SC - O(1)