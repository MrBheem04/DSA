class Solution {
public:
    struct Job {
        int id;
        int profit;
        int dead;
    };

    static bool comparison(Job a, Job b) {
        return a.profit > b.profit;
    }

    int find(int s, vector<int>& parent) {
        if (parent[s] == s)
            return s;
        return parent[s] = find(parent[s], parent);
    }

    vector<int> jobSequencing(vector<int>& deadline, vector<int>& profit) {

        int n = deadline.size();

        vector<Job> jobs;
        int maxi = 0;

        for (int i = 0; i < n; i++) {
            jobs.push_back({i + 1, profit[i], deadline[i]});
            maxi = max(maxi, deadline[i]);
        }

        sort(jobs.begin(), jobs.end(), comparison);

        vector<int> parent(maxi + 1);

        for (int i = 0; i <= maxi; i++)
            parent[i] = i;

        int countJobs = 0;
        int totalProfit = 0;

        for (int i = 0; i < n; i++) {
            int availableSlot = find(jobs[i].dead, parent);

            if (availableSlot > 0) {
                countJobs++;
                totalProfit += jobs[i].profit;

                parent[availableSlot] = find(availableSlot - 1, parent);
            }
        }

        return {countJobs, totalProfit};
    }
};