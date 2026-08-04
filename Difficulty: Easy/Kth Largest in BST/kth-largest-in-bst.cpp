/* Structure of a Binary Tree Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};*/

class Solution {
  public:
    int kthLargest(Node *root, int k) {
        // code here
        stack<Node*>st;
        Node* curr = root;
        
        while(curr != NULL || !st.empty()){
            while(curr != NULL){
                st.push(curr);
                curr = curr->right;
            }
            curr = st.top();
            st.pop();
            
            k--;
            if(k == 0){
                return curr->data;
            }
            curr = curr->left;
        }
        return -1;
    }
};