class Solution {
  public:
    vector<int> countGreater(vector<int> &arr, vector<int> &indices) {
        // code here
        int n = arr.size();
        vector<int>res;
        
        for(int idx : indices){
            int count = 0;
            
            for(int j=idx +1 ;j<n;j++){
                if(arr[j] > arr[idx]){
                    count++;
                }
            }
            res.push_back(count);
        }
        return res;
    }
};