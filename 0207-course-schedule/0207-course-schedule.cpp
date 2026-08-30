class Solution {
private:
    bool dfs(int node, vector<int>& vis, vector<int>& pathVis,
             vector<int> adj[]) {

        vis[node] = 1;
        pathVis[node] = 1;

        for (auto adjacentNode : adj[node]) {

            if (!vis[adjacentNode]) {

                if (dfs(adjacentNode, vis, pathVis, adj) == true) {
                    return true;
                }
            }
            else if (pathVis[adjacentNode]) {

                return true;
            }
        }

        // Remove from current DFS path
        pathVis[node] = 0;

        return false;
    }

public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

        vector<int> adj[numCourses];

        // Build directed graph
        for (auto prerequisite : prerequisites) {

            int course = prerequisite[0];
            int prerequisiteCourse = prerequisite[1];

            adj[prerequisiteCourse].push_back(course);
        }

        vector<int> vis(numCourses, 0);
        vector<int> pathVis(numCourses, 0);

        for (int i = 0; i < numCourses; i++) {

            if (!vis[i]) {

                if (dfs(i, vis, pathVis, adj) == true) {
                    return false;   // Cycle exists
                }
            }
        }

        return true;   // No cycle
    }
};