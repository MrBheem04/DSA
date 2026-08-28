class Solution {
  public:
    vector<int> bfs(vector<vector<int>> &adj) {
        // code here
        int v = adj.size();
        int vis[v] = {0};
        vis[0] = 1;
        
        queue<int>q;
        q.push(0);
        
        vector<int>dfs;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            dfs.push_back(node);
            
            for(auto it : adj[node]){
                if(!vis[it]){
                    vis[it] = 1;
                    q.push(it);
                }
            }
        }
        return dfs;
    }
};