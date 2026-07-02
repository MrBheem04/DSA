class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxlength = 0;
        int n = s.length();
        unordered_set<char>charSet;
        int left = 0;

        for(int right =0;right<n;right++){
            if(charSet.count(s[right]) == 0){
                charSet.insert(s[right]);
                maxlength = max(maxlength,right-left+1);
            }
            else{
                while(charSet.count(s[right])){
                    charSet.erase(s[left]);
                    left++;
                }
                charSet.insert(s[right]);
            }
        }
        return maxlength;
    }
};