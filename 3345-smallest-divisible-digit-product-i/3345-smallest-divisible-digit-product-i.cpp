class Solution {
public:
    int smallestNumber(int n, int t) {
        while(true){
            int digit = n;
            int temp = 1;
            while(digit){
                temp *= digit % 10;
                digit /= 10;
            }
            if(temp % t != 0){
                n++;
            }
            else{
                return n;
            }
        }
        return 0;
    }
};