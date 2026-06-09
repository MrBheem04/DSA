class Solution {
public:
    vector<int> findIntersectionValues(vector<int>& nums1, vector<int>& nums2) {
        set<int>st1(nums1.begin(),nums1.end());
        set<int>st2(nums2.begin(),nums2.end());

        int n  = nums1.size();
        int m = nums2.size();

        int count1 = 0;
        for(int i=0;i<n;i++){
            if(st2.count(nums1[i])){
                count1++;
            }
        }
        int count2 = 0;
        for(int i=0;i<m;i++){
            if(st1.count(nums2[i])){
                count2++;
            }
        }
        return{count1,count2};
    }
};