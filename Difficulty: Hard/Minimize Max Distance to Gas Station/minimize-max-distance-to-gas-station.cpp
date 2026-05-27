class Solution {
    int numberofgasstations(long double dist,vector<int>&nums){
        int n = nums.size();
        int count = 0;
        for(int i=1;i<n;i++){
            long double gap = nums[i]-nums[i-1];
            int numberInBetween = gap/dist;
            
            if(abs(gap-numberInBetween * dist) < 1e-6){
                numberInBetween--;
            }
            count += numberInBetween;
        }
        return count;
    }
  public:
    double minMaxDist(vector<int> &stations, int K) {
        // Code here
        int n = stations.size();
        long double low = 0;
        long double high = 0;
        
        for(int i=0;i<n-1;i++){
            high = max(high ,(long double)(stations[i+1]-stations[i]));
        }
        long double diff = 1e-6;
        while(high - low > diff){
            long double mid = (low + high)/(2.0);
            
            long double count = numberofgasstations(mid,stations);
            
            if(count > K){
                low = mid;
            }
            else{
                high = mid;
            }
        }
        return high;
    }
};