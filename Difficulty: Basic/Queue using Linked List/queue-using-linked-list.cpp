class Node {
	public:
	int data;
	Node* next;
	
	Node(int new_data) {
		data = new_data;
		next = nullptr;
	}
};

class myQueue {
	private:
	Node* start;
	Node* end ;
	int sz ;
	
	public:
	myQueue() {
		// Initialize your data members
		start = NULL;
		end = NULL;
		sz = 0;
	}
	
	bool isEmpty() {
		// check if the queue is empty
		return (sz == 0);
	}
	
	void enqueue(int x) {
		// Adds an element x at the rear of the queue
		Node* temp = new Node(x);
		if (start == NULL) {
			start = end = temp;
		}
		else {
			end->next = temp;
			end = temp;
		}
		sz++;
	}
	
	void dequeue() {
		// Removes the front element of the queue
		if(start == NULL){
		    return;
		}
		Node* temp = start;
		start = start->next;
		delete temp;
		sz--;
	}
	
	int getFront() {
		// Returns the front element of the queue
		// If queue is empty, return -1
		if(start == NULL){
		    return -1;
		}
		return start->data;
	}
	
	int size() {
		// Returns the current size of the queue.
		return sz;
	}
};
