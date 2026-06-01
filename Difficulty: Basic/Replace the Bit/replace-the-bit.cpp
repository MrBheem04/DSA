class Solution {
  public:
    int replaceBit(int n, int k) {
        // code here.
        int bits = floor(log2(n)) + 1;
        int pos = bits-k;
        return(n &~(1<<pos));
    }
};