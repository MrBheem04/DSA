class Solution {
public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        int prefix = n;

        vector<int>freq(2 * n + 1);
        freq[n] = 1;

        long long less = 0, ans = 0;

        for(int num : nums){
            if(num == target){
                less += freq[prefix++];
            }
            else{
                less -= freq[--prefix];
            }
            ++freq[prefix];
            ans += less;
        }
        return ans;
    }
};