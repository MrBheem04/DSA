class Solution {
  public:
    int countConnected(int V, vector<vector<int>>& edges) {
        // code here
        vector<vector<int>>adj(V);
        for(auto &e : edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        vector<int>visited(V, 0);
        int components = 0;
        
        for(int i=0;i<V;i++){
            
            if(!visited[i]){
                components++;
                
                queue<int>q;
                q.push(i);
                visited[i] = 1;
                
                while(!q.empty()){
                    int node = q.front();
                    q.pop();
                    
                    for(auto &nbr : adj[node]){
                        if(!visited[nbr]){
                            visited[nbr] = 1;
                            q.push(nbr);
                        }
                    }
                }
            }
        }
        return components;
    }
};