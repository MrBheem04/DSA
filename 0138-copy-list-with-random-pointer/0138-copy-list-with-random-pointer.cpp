/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
     void insertcopyBetween(Node* head){
        Node* temp = head;
        while(temp != NULL){
            Node* NextEle = temp->next;
            Node* copy = new Node(temp->val);

            copy->next = NextEle;
            temp->next = copy;

            temp = NextEle;
        }
    }
    void connectRandonPointer(Node* head){
        Node* temp = head;
        while(temp != NULL){
            Node* copyNode = temp->next;
            
            if(temp->random){
                copyNode->random = temp->random->next;
            }
            else{
                copyNode->random = nullptr;
            }
            temp = temp->next->next;
        }
    }
    Node* GetCopyList(Node* head){
        Node* temp = head;
        Node* dummy = new Node(-1);
        Node* res = dummy;

        while(temp != NULL){
            res->next = temp->next;
            res = res->next;

            temp->next = temp->next->next;
            temp = temp->next;
        }
        return dummy->next;
    }
public:
    Node* copyRandomList(Node* head) {
        if(head == NULL)return NULL;
        insertcopyBetween(head);
        connectRandonPointer(head);
        return GetCopyList(head);
    }
};