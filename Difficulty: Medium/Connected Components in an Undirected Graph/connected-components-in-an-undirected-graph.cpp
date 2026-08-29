class Solution {
	public:
	vector<vector<int>> getComponents(int V, vector<vector<int>> & edges) {
		// code here
		vector<vector<int>> adj(V);
		
		for (auto &e : edges) {
			adj[e[0]].push_back(e[1]);
			adj[e[1]].push_back(e[0]);
		}
		vector<int>visi(V, 0);
		
		vector<vector<int>> components;
		
		for (int i = 0; i<V; i++) {
			if (!visi[i]) {
				vector<int> component;
				
				queue<int>q;
				q.push(i);
				visi[i] = 1;
				
				while (!q.empty()) {
					int node = q.front();
					q.pop();
					
					component.push_back(node);
					
					for (auto &nbr : adj[node]) {
						if (!visi[nbr]) {
							visi[nbr] = 1;
							q.push(nbr);
						}
					}
				}
				components.push_back(component);
			}
		}
		return components;
	}
};
