class Solution {
public:
    int countDigitOne(int n) {
        long long ans = 0;

        for (long long position = 1; position <= n; position *= 10) {

            long long higher = n / (position * 10);
            long long current = (n / position) % 10;
            long long lower = n % position;

            if (current == 0) {
                ans += higher * position;
            } else if (current == 1) {
                ans += higher * position + lower + 1;
            } else {
                ans += (higher + 1) * position;
            }
        }
        return ans;
    }
};