/*
// Representation of a node
class Node {
public:
    int data;
    Node* next;

    Node(int d) {
        data = d;
        next = NULL;
    }
};
*/

class Solution {
  public:
    Node* arrayToList(vector<int>& arr) {
        // code here
        int n = arr.size();
        Node* head = new Node(arr[0]);
        Node* mover = head;
        for(int i=1;i<n;i++){
            Node*temp = new Node(arr[i]);
            mover->next = temp;
            mover = temp;
        }
        return head;
    }
};