class Solution {
public:
    bool sumGame(string num) {
        int n = num.size();

        int left = 0, right = 0;
        int qleft = 0, qright = 0;

        for (int i = 0; i < n / 2; i++) {
            if (num[i] == '?') {
                qleft++;
            } else {
                left += num[i] - '0';
            }
        }
        for (int i = n / 2; i < n; i++) {
            if (num[i] == '?') {
                qright++;
            } else {
                right += num[i] - '0';
            }
        }

        if((qleft + qright) % 2 == 1){
            return true;
        }
        return 2 * (left-right) != 9 * (qright - qleft);
    }
};