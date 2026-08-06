class Solution {
  public:
    int countMinOperations(vector<int>& arr) {
        // code here
        int n = arr.size();
        int ans = 0;
        while(true){
            for(int i=0;i<n;i++){
                if(arr[i] % 2){
                    arr[i]--;
                    ans++;
                }
                arr[i] /=2;
            }
            if(*max_element(arr.begin(),arr.end()) == 0)
            break;
            
            ans++;
        }
        return ans;
    }
};