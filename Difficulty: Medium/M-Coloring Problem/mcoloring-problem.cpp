class Solution {
    bool isSafe(int node, vector<int>& color,
                vector<int> adj[], int col) {

        for(auto it : adj[node]) {
            if(color[it] == col) {
                return false;
            }
        }
        return true;
    }

    bool solve(int node, vector<int>& color,
               int m, int v, vector<int> adj[]) {

        if(node == v)
            return true;

        for(int col = 1; col <= m; col++) {

            if(isSafe(node, color, adj, col)) {

                color[node] = col;

                if(solve(node + 1, color, m, v, adj))
                    return true;

                color[node] = 0; // backtrack
            }
        }

        return false;
    }

public:
    bool graphColoring(int v,
                       vector<vector<int>>& edges,
                       int m) {

        // Build adjacency list
        vector<int> adj[v];

        for(auto &e : edges) {
            int u = e[0];
            int w = e[1];

            adj[u].push_back(w);
            adj[w].push_back(u);
        }

        vector<int> color(v, 0);

        return solve(0, color, m, v, adj);
    }
};