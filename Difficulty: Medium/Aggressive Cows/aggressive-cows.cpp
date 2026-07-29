class Solution {
  public:
    bool canweplace(vector<int>& arr ,int cows ,int d){
        int n = arr.size();
        int count = 1;
        int lastpos = arr[0];
        
        for(int i=1;i<n;i++){
            if(arr[i] - lastpos >= d){
                count++;
                lastpos = arr[i];
            }
            if(count >= cows)return true;
        }
        return false;
    } 
    int aggressiveCows(vector<int> &arr, int k) {
        // code here
        int n = arr.size();
        
        sort(arr.begin(),arr.end());
        
        int low = 1;
        int high = arr[n-1]-arr[0];
        int ans = 0;
        
        while(low <= high){
            int mid = (low + high) /2;
            
            if(canweplace(arr,k,mid)){
                ans = mid;
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
        return ans;
    }
};