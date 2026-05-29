class Solution {
public:
    int minElement(vector<int>& nums) {
        int n = nums.size();
        int mini = INT_MAX;

        for (int i = 0; i < n; i++) {
            int num = nums[i];
            int currentsum = 0;

            while (num > 0) {
                currentsum = currentsum + num % 10;
                num = num / 10;
            }
            mini = min(mini, currentsum);
        }
        return mini;
    }
};