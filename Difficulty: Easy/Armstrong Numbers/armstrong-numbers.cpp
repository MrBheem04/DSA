// User function Template for C++
class Solution {
  public:
    bool armstrongNumber(int n) {
        // code here
        int sum = 0;
        int original = n;
        while(n != 0){
            int rem = n % 10;
            sum += pow(rem , 3);
            n = n/10;
        }
        return (original == sum);
    }
};