/* Structure of Linked List Node
class Node {
public:
    int data;
    Node* next;
    Node* bottom;

    Node(int x) {
        data = x;
        next = nullptr;
        bottom = nullptr;
    }
};
*/

class Solution {
public:

    Node* merge(Node* a, Node* b) {

        Node dummy(-1);
        Node* tail = &dummy;

        while (a && b) {
            if (a->data <= b->data) {
                tail->bottom = a;
                tail = a;
                a = a->bottom;
            } else {
                tail->bottom = b;
                tail = b;
                b = b->bottom;
            }

            tail->next = NULL;
        }

        if (a)
            tail->bottom = a;
        else
            tail->bottom = b;

        return dummy.bottom;
    }

    Node* flattenUtil(Node* head) {

        if (head == NULL || head->next == NULL)
            return head;

        // Find middle of horizontal list
        Node* slow = head;
        Node* fast = head->next;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        Node* second = slow->next;
        slow->next = NULL;

        Node* left = flattenUtil(head);
        Node* right = flattenUtil(second);

        return merge(left, right);
    }

    Node* flatten(Node* root) {
        return flattenUtil(root);
    }
};