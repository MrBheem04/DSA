class Solution {
    bool canweship(vector<int>& weights,int days,int capacity){
        int n =  weights.size();
        int usedDays = 1;
        int currentload = 0;

        for(int i=0;i<n;i++){
            if(currentload + weights[i] > capacity){
                usedDays++;
                currentload = 0;
            }
            currentload += weights[i];
        }
        return usedDays <= days;
    }
    int findmax(vector<int>&nums){
        int n=nums.size();
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
    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();
        int low = findmax(weights);
        int high = findsum(weights);
        int ans = 0;

        while(low <= high){
            int mid = (low + high)/2;

            if(canweship(weights,days,mid)){
                ans = mid;
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return ans;
    }
};