class myQueue {
    private:
    int *arr;
    int start;
    int end;
    int currsize ;
    int maxsize ;

  public:
    myQueue(int n) {
        // Define Data Structures
        maxsize = n;
        arr = new int[maxsize];
        start = -1;
        end = -1;
        currsize = 0;
    }

    bool isEmpty() {
        // check if the queue is empty
        return currsize == 0;
    }

    bool isFull() {
        // check if the queue is full
        return currsize == maxsize;
    }

    void enqueue(int x) {
        // Adds an element x at the rear of the queue.
        if(isFull()){
            return;
        }
        if(currsize == 0){
            start = 0;
            end = 0;
        }
        else{
            end = (end + 1)%maxsize;
        }
        arr[end] = x;
        currsize++;
    }

    void dequeue() {
        // Removes the front element of the queue.
        if(isEmpty()){
            return;
        }
        if(currsize == 1){
            start = -1;
            end = -1;
        }
        else{
            start = (start + 1) % maxsize;
        }
        currsize--;
    }

    int getFront() {
        // Returns the front element of the queue.
        if(isEmpty()){
            return -1;
        }
        return arr[start];
    }

    int getRear() {
        // Return the last element of queue
        if(isEmpty()){
            return -1;
        }
        return arr[end];
    }
};