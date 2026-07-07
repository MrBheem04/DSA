class Solution {
  public:
    int getSecondLargest(vector<int> &arr) {
        // code here
        int n = arr.size();
        int largest = INT_MIN;
        int slargest = INT_MIN;
        
        for(int i=0;i<n;i++){
            if(arr[i] > largest){
                slargest = largest;
                largest = arr[i];
            }
            else if(arr[i] > slargest && arr[i] != largest){
                slargest = arr[i];
            }
            
        }
        return (slargest == INT_MIN)?-1 : slargest;
    }
};