class Solution {
    int atMost(vector<int>& nums, int k) {
        int n = nums.size();
        int count = 0;
        int left = 0;

        unordered_map<int, int> freq;

        for (int right = 0; right < n; right++) {
            if (freq[nums[right]] == 0) {
                k--;
                ;
            }
            freq[nums[right]]++;

            while (k < 0) {
                freq[nums[left]]--;
                if (freq[nums[left]] == 0) {
                    k++;
                }
                left++;
            }
            count += right - left + 1;
        }
        return count;
    }

public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atMost(nums, k) - atMost(nums, k - 1);
    }
};