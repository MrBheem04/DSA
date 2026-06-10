class Solution {
    public int reverse(int x) {
        int reverse = 0;;
        while(x != 0){
            int lastdigit = x % 10;

            if (reverse > Integer.MAX_VALUE / 10 ||
                (reverse == Integer.MAX_VALUE / 10 && lastdigit > 7)) {
                return 0;
            }

            if (reverse < Integer.MIN_VALUE / 10 ||
                (reverse == Integer.MIN_VALUE / 10 && lastdigit < -8)) {
                return 0;
            }
            reverse = reverse * 10 + lastdigit;
            x = x/ 10;
        }
        return reverse;
    }
}