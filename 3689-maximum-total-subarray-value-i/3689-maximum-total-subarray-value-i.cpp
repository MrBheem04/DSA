typedef long long ll;
class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int maxi = *max_element(nums.begin(),nums.end());
        int mini=*min_element(nums.begin(),nums.end());
        ll diff=maxi-mini;
        return 1ll*diff*k;
    }
};