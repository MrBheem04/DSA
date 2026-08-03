/*
Definition for Node
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
}; */

class Solution {
  public:
    int findMaxFork(Node* root, int k) {
        // code here
        if(root == NULL)return -1;
        
        if(root->data > k){
            findMaxFork(root->left,k);
        }
        else{
            int res = findMaxFork(root->right,k);
            return (res == -1) ? root->data : res;
        }
    }
};