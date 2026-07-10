class Solution {
public:
    int arraySign(vector<int>& nums) {
        int negativecount = 0;

        for(int num : nums){
            if(num == 0){
                return 0;
            }
            if(num < 0){
                negativecount++;
            }
        }
        return (negativecount % 2  == 0) ? 1 : -1;
    }
};