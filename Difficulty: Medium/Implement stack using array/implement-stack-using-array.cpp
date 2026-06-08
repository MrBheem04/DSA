class myStack {
    private:
    int *arr;
    int capacity;
    int topIndex;
  public:
    myStack(int n) {
        // Define Data Structures
        capacity = n;
        arr = new int[capacity];
        topIndex = -1;
    }

    bool isEmpty() {
        // check if the stack is empty
        return topIndex == -1;
    }

    bool isFull() {
        // check if the stack is full
        return topIndex == capacity-1;
    }

    void push(int x) {
        // inserts x at the top of the stack
        if(isFull()){
            return;
        }
        topIndex++;
        arr[topIndex] = x;
    }

    int pop() {
        // removes an element from the top of the stack
        if(isEmpty()){
            return -1;
        }
        return arr[topIndex--]; 
    }

    int peek() {
        // Returns the top element of the stack
        if(isEmpty()){
            return -1;
        }
        return arr[topIndex];
    }
};