/* Structure of a Tree Node
class Node {
public:
    int data;
    Node* left, *right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
}; */

class Solution {
  public:
    bool isSumProperty(Node *root) {
        // code here
        if(root == NULL ){
            return true;
        }
        if(root->left == NULL && root->right == NULL){
            return true;
        }
        int leftData = 0;
        int rightData = 0;
        
        if(root->left != NULL){
            leftData = root->left->data;
        }
        if(root->right != NULL){
            rightData = root->right->data;
        }
        if(root->data == leftData + rightData){
            return isSumProperty(root->left) && isSumProperty(root->right);
        }
        return false;
    }
};