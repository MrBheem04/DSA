class Solution {
	private:
	bool detect(int src, vector<int>adj[], vector<int>&visi) {
		visi[src] = 1;
		
		queue<pair<int, int>> q;
		q.push({src, -1});
		
		while (!q.empty()) {
			int node = q.front().first;
			int parent = q.front().second;
			q.pop();
			
			for (auto adjacenceNode : adj[node]) {
				if (!visi[adjacenceNode]) {
					visi[adjacenceNode] = 1;
					q.push({adjacenceNode, node});
				}
				else if (parent != adjacenceNode) {
					return true;
				}
			}
		}
		return false;
	}
	public:
	bool isCycle(int V, vector<vector<int>> & edges) {
		// Code here
		vector<int>adj[V];
		
		for (auto edge : edges) {
			int u = edge[0];
			int v = edge[1];
			
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		vector<int>visi(V, 0);
		for (int i = 0; i<V; i++) {
			if (!visi[i]) {
				if (detect(i, adj, visi)) {
					return true;
				}
			}
		}
		return false;
	}
};
