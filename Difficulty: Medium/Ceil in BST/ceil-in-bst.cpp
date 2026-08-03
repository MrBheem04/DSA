/*
Definition for Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/

class Solution {
  public:
    int findCeil(Node* root, int x) {
        // code here
        if(root == NULL)return -1;
        
        if(root->data == x)return root->data;
        if(root->data < x){
            return findCeil(root->right,x);
        }
        int ceil = findCeil(root->left,x);
        return ceil>= x ?ceil : root->data;
    }
};
