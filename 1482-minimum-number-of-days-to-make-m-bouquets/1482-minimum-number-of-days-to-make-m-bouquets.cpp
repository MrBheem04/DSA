class Solution {
    bool possible(vector<int>&nums,int m,int k,int days){
        int n = nums.size();
        int nofb = 0;
        int count = 0;

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
        return nofb >= m; 
    }
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        long long val = m *1LL * k * 1LL;

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
            int mid = (low + high)/2;

            if(possible(bloomDay,m,k,mid)){
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return low;
    }
};