class Solution {
private:
    vector<int> toposort(int V, vector<vector<int>>& adj) {

        vector<int> indegree(V, 0);

        // Calculate indegree
        for (int i = 0; i < V; i++) {
            for (auto it : adj[i]) {
                indegree[it]++;
            }
        }

        queue<int> q;

        // Push all characters having indegree 0
        for (int i = 0; i < V; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        vector<int> topo;

        while (!q.empty()) {

            int node = q.front();
            q.pop();

            topo.push_back(node);

            for (auto it : adj[node]) {

                indegree[it]--;

                if (indegree[it] == 0) {
                    q.push(it);
                }
            }
        }

        return topo;
    }

public:
    string findOrder(vector<string>& words) {

        int n = words.size();
        int k = 26;

        vector<vector<int>> adj(k);

        // Characters actually present in words
        vector<int> used(k, 0);

        for (auto& word : words) {
            for (char ch : word) {
                used[ch - 'a'] = 1;
            }
        }

        // To avoid duplicate edges
        vector<vector<int>> edge(k, vector<int>(k, 0));

        // Build graph
        for (int i = 0; i < n - 1; i++) {

            string s1 = words[i];
            string s2 = words[i + 1];

            int len = min(s1.size(), s2.size());

            bool found = false;

            // First different character determines the order
            for (int j = 0; j < len; j++) {

                if (s1[j] != s2[j]) {

                    int u = s1[j] - 'a';
                    int v = s2[j] - 'a';

                    // Add edge only once
                    if (!edge[u][v]) {
                        adj[u].push_back(v);
                        edge[u][v] = 1;
                    }

                    found = true;
                    break;
                }
            }

            // Invalid case:
            // ["abcd", "ab"]
            if (!found && s1.size() > s2.size()) {
                return "";
            }
        }

        // Topological sort
        vector<int> topo = toposort(k, adj);

        // Number of characters actually present
        int total = 0;

        for (int i = 0; i < k; i++) {
            if (used[i]) {
                total++;
            }
        }

        // Build answer using only used characters
        string ans = "";
        int count = 0;

        for (auto node : topo) {

            if (used[node]) {
                ans += char(node + 'a');
                count++;
            }
        }

        // If not all used characters are in topo,
        // there is a cycle.
        if (count != total) {
            return "";
        }

        return ans;
    }
};