class Solution {
    int fun(int n){
        if(n % 4 == 1)return 1;
        if(n % 4 == 2)return n+1;
        if(n % 4 == 3)return 0;
        return n;
    }
  public:
    int findXOR(int l, int r) {
        // code here
        return fun(l-1)^fun(r);
    }
};