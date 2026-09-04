class Solution {
private:
    bool dfsCheck(int node, vector<vector<int>>& adj, vector<int>& vis,
                  vector<int>& pathvis, vector<int>& order) {
        vis[node] = 1;
        pathvis[node] = 1;

        for (auto it : adj[node]) {
            if (!vis[it]) {
                if (dfsCheck(it, adj, vis, pathvis,order))
                    return true;
            } else if (pathvis[it] == true)
                return true;
        }
        pathvis[node] = 0;
        order.push_back(node);
        return false;
    }

public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);

        for (auto it : prerequisites) {
            int course = it[0];
            int prerequisites = it[1];

            adj[prerequisites].push_back(course);
        }
        vector<int> vis(numCourses, 0);
        vector<int> pathvis(numCourses, 0);
        vector<int> order;

        for (int i = 0; i < numCourses; i++) {
            if (!vis[i]) {
                if (dfsCheck(i, adj, vis, pathvis,order))
                    return {};
            }
        }
        reverse(order.begin(),order.end());
        return order;
    }
};