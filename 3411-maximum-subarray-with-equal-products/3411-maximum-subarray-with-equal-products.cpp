class Solution {
public:
    int maxLength(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            long long product = 1;
            int g = 0;
            long long l = 1;

            for (int j = i; j < n; j++) {

                if(product > LLONG_MAX / nums[j]){
                    break;
                }
                product *= nums[j];
                g = gcd(g, nums[j]);
                l = lcm(l, nums[j]);

                if (product == 1LL * g * l) {
                    ans = max(ans, j - i + 1);
                }
            }
        }
        return ans;
    }
};