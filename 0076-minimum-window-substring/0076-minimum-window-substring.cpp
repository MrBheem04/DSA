class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size();
        int m = t.size();

        vector<int>hash(256,0);

        int l=0;
        int r=0;
        int minLen = INT_MAX;
        int stIndex = -1;
        int count = 0;

        for(char c : t){
            hash[c]++;
        }
        while(r < n){
            if(hash[s[r]] > 0){
                count++;
            }
            hash[s[r]]--;
            while(count == m){
                if(r-l+1 < minLen){
                    minLen = r-l+1;
                    stIndex = l;
                }
                hash[s[l]]++;
                if(hash[s[l]] > 0){
                    count--;
                }
                l++;
            }
            r++;
        }
        return stIndex == -1 ?"" : s.substr(stIndex,minLen);
    }
};