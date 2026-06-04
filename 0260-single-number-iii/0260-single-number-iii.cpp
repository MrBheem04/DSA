class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int n = nums.size();
        long xorr = 0;

        for (int i = 0; i < n; i++) {
            xorr = xorr ^ nums[i];
        }
        int rightmost = (xorr & (-xorr));
        int bu1 = 0;
        int bu2 = 0;
        for(int i=0;i<n;i++){
            if(nums[i] &  rightmost){
                bu1 = bu1^nums[i];
            }
            else{
                bu2 = bu2^nums[i];
            }
        }
        return{bu1,bu2};
    }
};