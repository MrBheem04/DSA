// User function Template for C++
class Solution {
  public:
    int findCeil(vector<int>& nums, int x) {
        // code here
        int n = nums.size();
        int low = 0;
        int high = n-1;
        int ans = -1;
        
        while(low <= high){
            int mid = (low + high)/2;
            
            if(nums[mid] >= x){
                ans = mid;
                high = mid -1;
            }
            else{
                low = mid+1;
            }
        }
        return ans;
    }
};