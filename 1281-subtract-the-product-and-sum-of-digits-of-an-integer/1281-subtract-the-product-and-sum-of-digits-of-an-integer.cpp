class Solution {
public:
    int subtractProductAndSum(int n) {
        while( n < 1) return 0;

        int res = 0;
        int product =1;
        int sum = 0;
        while( n != 0){
            int digit = n % 10;
            product = product*digit;
            sum = sum + digit;
            res = product - sum;
            n = n/10;
        }
        return res;
    }
};