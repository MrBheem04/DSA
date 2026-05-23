class Solution {
    int canplace(vector<int>&stalls,int cows,int d){
        int n = stalls.size();
        int count = 1;
        int lastposi = stalls[0];
        
        for(int i=0;i<n;i++){
            if(stalls[i] - lastposi >= d){
                count++;
                lastposi = stalls[i];
            }
            if(count >= cows)return true;
        }
        return false;
    }
  public:
    int aggressiveCows(vector<int> &stalls, int k) {
        // code here
        int n = stalls.size();
        sort(stalls.begin(),stalls.end());
        int low = 1;
        int high = stalls[n-1]-stalls[0];
        int ans = 0;
        
        while(low <= high){
            int mid = (low + high)/2;
            
            if(canplace(stalls,k,mid)){
                ans = mid;
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
        return ans;
    }
};