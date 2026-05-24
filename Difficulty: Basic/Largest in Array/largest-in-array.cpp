class Solution {
  public:
    int largest(vector<int> &arr) {
        // code here
        int n = arr.size();
        int maxi = 0;
        for(int i=0;i<n;i++){
            maxi = max(maxi,arr[i]);
        }
        return maxi;
    }
};
