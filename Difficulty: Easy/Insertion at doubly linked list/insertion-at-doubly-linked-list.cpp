/*
class Node {
  public:
    int data;
    Node* next;
    Node* prev;

    Node(int x) {
        data = x;
        next = prev = nullptr;
    }
};
*/

class Solution {
  public:
    Node *insertAtPos(Node *head, int p, int x) {
        // code here
        Node* newNode = new Node(x);
        
        if(head == NULL){
            return newNode;
        }
        
        Node*temp = head;
        for(int i=0;i<p && temp->next != NULL;i++){
            temp=temp->next;
        }
        newNode->next = temp->next;
        newNode->prev = temp;
        
        if(temp->next)
            temp->next->prev = newNode;
            
            temp->next = newNode;
        return head;
    }
};