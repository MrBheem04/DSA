class Solution {
    bool ispossible(vector<int>&nums,int m ,int k,int days){
        int n = nums.size();
        int count = 0;
        int nofb = 0;

        for(int i=0;i<n;i++){
            if(nums[i] <= days){
                count++;
            }
            else{
                nofb += (count / k);
                count = 0;
            }
        }
        nofb += (count / k);
        return nofb>=m;
    }
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        long long val = 1LL * m * 1LL * k;
        if(val > n){
            return -1;
        }
        int mini = INT_MAX;
        int maxi = INT_MIN;

        for(int i=0;i<n;i++){
            mini = min(mini,bloomDay[i]);
            maxi = max(maxi,bloomDay[i]);
        }
        int low = mini;
        int high = maxi;

        while(low <= high){
            int mid =(low + high)/2;

            if(ispossible(bloomDay , m,k,mid)){
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return low;
    }
};