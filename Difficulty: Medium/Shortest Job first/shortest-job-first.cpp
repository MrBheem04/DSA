class Solution {
  public:
    int solve(vector<int>& bt) {
        // code here
        sort(bt.begin(),bt.end());
        
        int waitTime = 0;
        int totalTime = 0;
        int n= bt.size();
        
        for(int i=0;i<n;i++){
            waitTime += totalTime;
            totalTime += bt[i];
        }
        return waitTime / n;
    }
};