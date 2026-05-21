class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        
        int n = strs.size();
        sort(strs.begin(),strs.end());
        string ans ="";
        string first = strs[0];
        string last = strs[n-1];

        int mini = 0;
        mini = min(first.size(),last.size());

        for(int i=0;i<mini;i++){
            if(first[i] != last[i]){
            return ans;
        }
        ans += first[i];
        }
        return ans;
    }
};