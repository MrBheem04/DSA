class Solution {
    int findmax(vector<int>&nums){
        int n = nums.size();
        int maxi = INT_MIN;
        for(int i=0;i<n;i++){
            maxi = max(maxi,nums[i]);
        }
        return maxi;
    }
    long long calculateHour(vector<int>&nums,int hourly){
        int n = nums.size();
        long long TotalHours = 0;
        for(int i=0;i<n;i++){
            TotalHours += ceil((double)(nums[i])/ (double)(hourly));
        }
        return TotalHours;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();

        int low = 1;
        int high = findmax(piles);

        while(low <= high){
            long long mid = (low + high)/2;

            long long TotalHours =calculateHour(piles,mid);
            if(TotalHours <= h){
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return low;
    }
};