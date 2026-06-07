/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode GetKthNode(ListNode head, int k){     
        k -= 1;
        while(head != null && k > 0){
            k--;
            head = head.next;
        }
        return head;
    }
    public ListNode reverseLinkList(ListNode head){
        ListNode prev = null;
        ListNode curr = head;

        while(curr != null){
            ListNode nextNode = curr.next;
            curr.next = prev;
            prev = curr;
            curr = nextNode;
        }
        return prev;
    }
    public ListNode reverseKGroup(ListNode head, int k) {
        ListNode prevNode = null;
        ListNode temp = head;

        while(temp != null){
            ListNode KthNode = GetKthNode(temp,k);
            if(KthNode == null){
                if(prevNode != null)prevNode.next = temp;
                break;
            }
            ListNode nextNode = KthNode.next;
            KthNode.next = null;
            reverseLinkList(temp);
            if(temp == head){
                head = KthNode;
            }
            else{
                prevNode.next = KthNode;
            }
            prevNode = temp;
            temp = nextNode;
        }
        return head;
    }
}