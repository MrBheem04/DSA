class Solution {
public:
    string smallestSubsequence(string s) {
        int last[26] = {0};
        bool seen[26] = {false};
        string res = "";

        for (int i = 0; i < s.length(); i++) {
            last[s[i] - 'a'] = i;
        }
        for (int i = 0; i < s.length(); i++) {
            int c = s[i] - 'a';
            if (seen[c])
                continue;

            while (!res.empty() && res.back() > s[i] &&
                   last[res.back() - 'a'] > i) {
                seen[res.back() - 'a'] = false;
                res.pop_back();
            }
            res.push_back(s[i]);
            seen[c] = true;
        }
        return res;
    }
};