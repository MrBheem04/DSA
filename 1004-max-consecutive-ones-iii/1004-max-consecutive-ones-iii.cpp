class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int left = 0;
        int zerocount = 0;
        int maxLen = 0;
        for(int right =0;right<n;right++){
            if(nums[right] == 0){
                zerocount++;
            }
            if(zerocount > k){
                if(nums[left] == 0){
                    zerocount--;
                }
                left++;
            }
            maxLen = max(maxLen,right-left+1);
        }
        return maxLen;
    }
};