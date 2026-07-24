/*
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
*/

class Solution {
  public:
  void LeftView(Node* root,int level ,vector<int>& res){
      if(!root){
          return;
      }
      if(res.size() == level){
          res.push_back(root->data);
      }
      LeftView(root->left,level+1,res);
      LeftView(root->right,level+1,res);
     
  }
    vector<int> leftView(Node *root) {
        // code here
        vector<int>res;
        LeftView(root,0,res);
        return res;
    }
};