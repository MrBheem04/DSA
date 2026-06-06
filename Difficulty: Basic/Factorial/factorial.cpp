class Solution {
  public:
    int factorial(int n) {
        // code here
        if(n <= 1){
            return n;
        }
        return n * factorial(n-1);
    }
};