class Solution {
    void fun(int i,int j,vector<vector<int>>&arr,int n,vector<string>&ans,
     string move,vector<vector<int>>&vis,int di[],int dj[]){
        if(i == n-1 && j == n-1){
            ans.push_back(move);
            return;
        }
                vis[i][j] = 1;
                
        string dir = "DLRU";
        for(int ind = 0;ind<4;ind++){
            int nexti = i + di[ind];
            int nextj = j + dj[ind];
            if(nexti >= 0 && nextj >= 0 && nexti <n &&
            nextj < n && !vis[nexti][nextj] && arr[nexti][nextj] == 1){
                fun(nexti,nextj,arr,n,ans,move+dir[ind],vis,di,dj);
            }
        }
        vis[i][j] = 0;
    }
  public:
    vector<string> ratInMaze(vector<vector<int>>&m) {
        int n = m.size();
        // code here
        vector<string>ans;
        vector<vector<int>>vis(n,vector<int>(n,0));
        int di[] ={+1 , 0 , 0 , -1};
        int dj[] ={0 , -1 ,+1 , 0 };
        if(m[0][0] == 1) fun(0,0,m,n,ans,"",vis,di,dj);
        return ans;
    }
};