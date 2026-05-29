class Solution {
    int lowerbound(vector<int>&nums,int x){
        int n =nums.size();
        int low = 0;
        int high = n-1;
        int ans = n;
        
        while(low <= high ){
            int mid =(low + high)/2;
            
            if(nums[mid] >= x){
                ans = mid;
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return ans;
    }
  public:
    int rowWithMax1s(vector<vector<int>> &arr) {
        // code here
        int n = arr.size();
        int m = arr[0].size();
        
        int max_ones = 0;
        int ind = -1;
        for(int i=0;i<n;i++){
            int count_ones = m-lowerbound(arr[i],1);
            if( count_ones > max_ones){
                max_ones = count_ones;
                ind = i;
            }
        }
        return ind;
    }
};