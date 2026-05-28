class Solution {
    int upperbound(vector<int>&nums,int x){
        int n = nums.size();
        int low = 0;
        int high = n-1;
        int ans = n;
        while(low <= high){
            int mid = (low + high)/2;
            
            if(nums[mid] > x){
                ans = mid;
                high = mid-1;
            }
            else{
                low =  mid+1;
            }
        }
        return ans;
    }
    int countsmallequal(vector<vector<int>>&mat , int n ,int m ,int x){
        int count = 0;
        for(int i=0;i<n;i++){
            count += upperbound(mat[i],x);
        }
        return count;
    }
  public:
    int median(vector<vector<int>> &mat) {
        // code here
        int n = mat.size();
        int m = mat[0].size();
        int low =INT_MAX,high = INT_MIN;
        
        for(int i=0;i<n;i++){
            low = min(low, mat[i][0]);
            high = max(high ,mat[i][m-1]);
        }
        
        int req = (n * m)/2;
        while(low <= high){
            int mid = (low + high)/2;
            
            int smallequal = countsmallequal(mat,n,m,mid);
            if(smallequal <= req) low = mid+1;
            else high = mid-1;
        }
        return low;
    }
};
