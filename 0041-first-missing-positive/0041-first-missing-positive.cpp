class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());

        int first = 1;
        for(int i=0;i<n;i++){
            if(nums[i] <= 0)continue;
            if(nums[i] == first){
                first++;
            }
            else if(nums[i] > first){
                return first;
            }
        }
        return first;
    }
};