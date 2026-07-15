class Solution {
public:
    static bool cmp(vector<int> &a, vector<int> &b) {
        if (a[0] == b[0])
            return a[2] < b[2];   // smaller index first
        return a[0] < b[0];       // smaller finish time first
    }

    vector<int> maxMeetings(vector<int> &s, vector<int> &f) {
        int n = s.size();

        vector<vector<int>> meetings;

        for (int i = 0; i < n; i++) {
            meetings.push_back({f[i], s[i], i + 1});
        }

        sort(meetings.begin(), meetings.end(), cmp);

        vector<int> ans;
        int lastEnd = -1;

        for (auto &m : meetings) {
            int end = m[0];
            int start = m[1];
            int idx = m[2];

            if (start > lastEnd) {
                ans.push_back(idx);
                lastEnd = end;
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};