class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1,
                               int k2) {
        int n = nums1.size();
        int m = 0;
        long long k = 1LL * k1 + k2;
        vector<int> diff(n);

        for (int i = 0; i < n; i++) {
            m = max(m, diff[i] = abs(nums1[i] - nums2[i]));
        }

        vector<int> bucket(m + 1);
        for (int x : diff)
            bucket[x]++;

        for (int i = m; i > 0 && k > 0; i--) {
            int take = min((long long)bucket[i], k);
            bucket[i] -= take;
            bucket[i - 1] += take;
            k -= take;
        }
        long long ans = 0;
        for (int i = 1; i <= m; i++) {
            ans += 1LL * bucket[i] * i * i;
        }
        return ans;
    }
};