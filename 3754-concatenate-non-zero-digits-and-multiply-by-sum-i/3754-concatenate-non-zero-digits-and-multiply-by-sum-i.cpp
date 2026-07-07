class Solution {
public:
    long long sumAndMultiply(int n) {

        if (n == 0)
            return 0;
        vector<int> digits;

        while (n > 0) {
            digits.push_back(n % 10);
            n /= 10;
        }
        reverse(digits.begin(), digits.end());

        long long x = 0;
        int sum = 0;

        for (int digit : digits) {
            if (digit != 0) {
                x = x * 10 + digit;
                sum += digit;
            }
        }
        return x * sum;
    }
};