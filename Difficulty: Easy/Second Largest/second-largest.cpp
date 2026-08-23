class Solution {
  public:
    int getSecondLargest(vector<int> &arr) {
        // code here
        int n = arr.size();
        int largest = arr[0];
        int slargest = -1;
        
        for(int i=1;i<n;i++){
            if(arr[i] > largest){
                slargest  = largest;
                largest = arr[i];
            }
            else if(arr[i] > slargest && arr[i] != largest){
                slargest = arr[i];
            }
        }
        return slargest;
    }
};