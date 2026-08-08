class myStack {
    private:
    int * arr;
    int capcity;
    int topIndex;
  public:
    myStack(int n) {
        // Define Data Structures
        capcity = n;
        arr = new int[capcity];
        topIndex = -1;
    }

    bool isEmpty() {
        // check if the stack is empty
        return topIndex == -1;
    }

    bool isFull() {
        // check if the stack is full
        return topIndex == capcity-1;
    }

    void push(int x) {
        // inserts x at the top of the stack
        if(isFull()){
            return;
        }
        topIndex++;
        arr[topIndex] = x;
    }

    void pop() {
        // removes an element from the top of the stack
        if(isEmpty()){
            return;
        }
        topIndex--;
        
    }

    int peek() {
        // Returns the top element of the stack
        if(isEmpty()){
            return -1;
        }
        return arr[topIndex];
    }
};