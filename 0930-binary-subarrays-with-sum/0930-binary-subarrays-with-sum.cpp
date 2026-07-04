class Solution {
    private:
    int Atmost(vector<int>&nums,int goal){
        int n = nums.size();
        if(goal < 0) return 0;

        int l = 0;
        int sum = 0;
        int count = 0;

        for(int r=0;r<n;r++){
            sum += nums[r];

            while(sum > goal){
                sum -= nums[l];
                l++;
            }
            count += (r-l+1);
        }
        return count;
    }
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return Atmost(nums,goal) - Atmost(nums,goal-1);
    }
};