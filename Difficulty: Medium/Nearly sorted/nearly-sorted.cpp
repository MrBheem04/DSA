class Solution {
  public:
    void nearlySorted(vector<int>& arr, int k) {
        // code here
        priority_queue<int,vector<int>,greater<int>>minHeap;
        vector<int>result;
        
        for(int i=0;i<=k && i<arr.size();i++){
            minHeap.push(arr[i]);
        }
        for(int i=k+1;i<arr.size();i++){
            result.push_back(minHeap.top());
            minHeap.pop();
            
            minHeap.push(arr[i]);
        }
        while(!minHeap.empty()){
            result.push_back(minHeap.top());
            minHeap.pop();
        }
        arr = result;
    }
};