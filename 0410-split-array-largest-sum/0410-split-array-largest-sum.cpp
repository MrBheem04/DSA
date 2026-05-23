class Solution {
    int countpartition(vector<int>&nums,int maxsum){
        int n = nums.size();
        int partition = 1;
        int subarraysum = 0;

        for(int i=0;i<n;i++){
            if(subarraysum + nums[i] <= maxsum){
                subarraysum += nums[i];
            }
            else{
                partition++;
                subarraysum = nums[i];
            }
        }
        return partition;
    }
    int findmax(vector<int>&nums){
        int n = nums.size();
        int maxi = INT_MIN;
        
        for(int i=0;i<n;i++){
            maxi = max(maxi,nums[i]);
        }
        return maxi;
    }
    int findsum(vector<int>&nums){
        int n = nums.size();
        int sum = 0;
        for(int i=0;i<n;i++){
            sum += nums[i];
        }
        return sum;
    }
public:
    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();

        if(k > n){
            return -1;
        }
        int low = findmax(nums);
        int high = findsum(nums);

        while(low <= high){
            int mid = (low + high)/2;

            long long partition = countpartition(nums,mid);

            if(partition > k){
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
        return low;
    }
};