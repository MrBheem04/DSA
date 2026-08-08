/* Structure of linked list Node
class Node {
  public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};*/

class myStack {
private:
Node* top;
int sz;
  public:
    myStack() {
        // Initialize your data members
        top = NULL;
        sz = 0;
    }

    bool isEmpty() {
        // check if the stack is empty
        return (sz == 0);
    }

    void push(int x) {
        // Adds an element x at the top of the stack
        Node* temp = new Node(x);
        temp->next = top;
        top = temp;
        sz++;
    }

    void pop() {
        // Removes the top element of the stack
        Node* temp = top;
        top = top->next;
        delete temp;
        sz--;
    }

    int peek() {
        // Returns the top element of the stack
        // If stack is empty, return -1
        if(isEmpty()){
            return -1;
        }
        return top->data;
    }

    int size() {
        // Returns the current size of the stack
        return sz;
    }
};