class Solution {
    int countpartition(vector<int>& nums, int maxsum) {
        int n = nums.size();
        int partition = 1;
        int subArraysum = 0;

        for (int i = 0; i < n; i++) {
            if (nums[i] + subArraysum > maxsum) {
                partition++;
                subArraysum = 0;
            }
            subArraysum += nums[i];
        }
        return partition;
    }

public:
    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();

        int low = *max_element(nums.begin(), nums.end());
        int high = accumulate(nums.begin(), nums.end(),0);

        while (low <= high) {
            int mid = (low + high) / 2;

            int partition = countpartition(nums, mid);

            if (partition <= k) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }
};