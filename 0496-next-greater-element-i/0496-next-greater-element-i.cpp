class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int>st;
        int n = nums2.size();
        vector<int>res(n);

        for(int i=n-1;i>=0;i--){

            while(!st.empty() && st.top() <= nums2[i]){
                st.pop();
            }
            if(st.empty()) res[i] = -1;
            else res[i] = st.top();

            st.push(nums2[i]);
        }
            unordered_map<int,int>mp;
            for(int i=0;i<n;i++){
                mp[nums2[i]] = res[i];
            }
            vector<int>ans;
            for(int x : nums1){
                ans.push_back(mp[x]);
        }
        return ans;
    }
};