class Solution {
public:
    void findcombination(int ind, int target, vector<int>&nums,
                         vector<vector<int>>&ans, vector<int>&ds) {
        if (ind == nums.size()) {
            if (target == 0) {
                ans.push_back(ds);
            }
            return;
        }

        if (nums[ind] <= target) {
            ds.push_back(nums[ind]);
            findcombination(ind, target - nums[ind], nums, ans, ds);
            ds.pop_back();
        }
        findcombination(ind + 1, target, nums, ans, ds);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>ds;
        findcombination(0,target,candidates,ans,ds);
        return ans;
    }
};