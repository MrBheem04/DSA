class Solution {
public:
    int divide(int dividend, int divisor) {
        if(divisor == 0){
            return INT_MAX;
        }
        if(dividend == divisor){
            return 1;
        }
        if(dividend == INT_MIN && divisor == -1){
            return INT_MAX;
        }
        if(divisor == 1){
            return dividend;
        }

        bool sign = true;

        if(dividend > 0 && divisor < 0 || dividend < 0 && divisor > 0){
            sign = false;
        }

        long long n = dividend;
        long long d = divisor;

        n = abs(n);
        d = abs(d);

        long long sum = 0;
        long long ans = 0;

        while(sum + d <= n){
            ans++;
            sum +=d;
        }
        if(ans > INT_MAX && sign){
            return INT_MAX;
        }
        if(ans > INT_MAX && !sign){
            return INT_MIN;
        }
        return sign ? ans : -1* ans;
    }
};