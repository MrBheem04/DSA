class maxHeap {
	private:
	// Initialize your data members
	vector<int>heap;
	public:
	
	void push(int x) {
		// Insert x into the heap
		heap.push_back(x);
		int i = heap.size() - 1;
		
		while (i > 0) {
			int parent = (i - 1)/2;
			if (heap[parent] < heap[i]) {
				swap(heap[parent], heap[i]);
				i = parent;
			}
			else {
				break;
			}
		}
	}
	
	void pop() {
		// Remove the top (maximum) element
		if (heap.empty())return;
		heap[0] = heap.back();
		heap.pop_back();
		
		int i = 0;
		int n = heap.size();
		
		while (true) {
			int left = 2*i + 1;
			int right = 2*i + 2;
			int largest = i;
			
			while (left < n && heap[largest] < heap[left]) {
				largest = left;
			}
			while(right < n && heap[largest] < heap[right]){
			    largest = right;
			}
			if(largest != i){
			    swap(heap[i],heap[largest]);
			    i=largest;
			}
			else{
			    break;
			}
		}
	}
	int peek() {
		// Return the top element or -1 if empty
		if(heap.empty())return -1;
		return heap[0];
	}
	
	int size() {
		// Return the number of elements in the heap
		return heap.size();
	}
};
