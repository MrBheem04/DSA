class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();

        int left = 0;
        int right = n - 1;
        int totalwater = 0;

        int maxLeft = 0;
        int maxRight = 0;

        while (left <= right) {
            if (height[left] <= height[right]) {
                if (height[left] >= maxLeft) {
                    maxLeft = height[left];
                } else {
                    totalwater += maxLeft - height[left];
                }
                left++;
            } else {
                if (height[right] >= maxRight) {
                    maxRight = height[right];
                } else {
                    totalwater += maxRight - height[right];
                }
                right--;
            }
        }
        return totalwater;
    }
};