class Solution {
public:
    long long calculateHours(vector<int>&nums,int hourly){
        int n = nums.size();
        long long TotalHours = 0;
        for(int i=0;i<n;i++){
            TotalHours += ceil((double)(nums[i])/ (double)(hourly));
        }
        return TotalHours;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int low = 1;
        int high = *max_element(piles.begin(),piles.end());

        while(low <= high){
            int mid =(low + high)/2;

            long long TotalHours = calculateHours(piles,mid);

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