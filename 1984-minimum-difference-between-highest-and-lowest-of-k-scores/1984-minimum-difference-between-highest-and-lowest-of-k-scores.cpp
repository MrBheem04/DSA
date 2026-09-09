class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        int n = nums.size();
        if(n == 1){
            return 0;
        }
        sort(nums.begin(),nums.end());
        int i=0;
        int diff = INT_MAX;

        for(int j=k-1;j<n;j++){
            if((j-i+1) > k){
                i++;
            }
            diff = min(diff,nums[j]-nums[i]);
        }
        return diff;
    }
};