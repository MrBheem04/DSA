class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        int smallest = INT_MIN;
        int longest = 0;
        int count = 0;

        sort(nums.begin(),nums.end());

        for(int i=0;i<n;i++){
            if(nums[i]-1 == smallest){
                count++;
               smallest = nums[i];
            }
            else if(nums[i] != smallest){
                count = 1;
                smallest = nums[i];
            }
            longest = max(longest,count);
        }
        return longest;
    }
};