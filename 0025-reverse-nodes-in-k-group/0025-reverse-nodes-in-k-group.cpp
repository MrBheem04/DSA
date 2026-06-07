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
class Solution {
public:
ListNode* GetKthNode(ListNode* head,int k){
    k -= 1;
    while(head != NULL && k > 0){
        k--;
        head = head->next;
    }
    return head;
}
ListNode* ReverseLinkList(ListNode* head){
    ListNode* prev = NULL;
    ListNode* curr = head;

    while(curr != NULL){
        ListNode* nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    }
    return prev;
}
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        ListNode* prevNode = NULL;

        while(temp != NULL){
            ListNode* KthNode = GetKthNode(temp,k);

            if(KthNode == NULL){

                if(prevNode)prevNode->next = temp;
                break;
            }
            ListNode* nextNode = KthNode->next;
            KthNode->next = NULL;
            ReverseLinkList(temp);
            if(temp == head){
                head = KthNode;
            }
            else{
                prevNode->next = KthNode;
            }
            prevNode = temp;
            temp = nextNode;
        }
        return head;
    }
};