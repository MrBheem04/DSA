class Solution {
    bool canweship(vector<int>&weights,int days ,int capacity){
        int n = weights.size();
        int currentLoad = 0;
        int usedDays = 1;

        for(int i=0;i<n;i++){
            if(weights[i] + currentLoad > capacity){
                usedDays++;
                currentLoad = 0;
            }
            currentLoad += weights[i];
        }
        return usedDays <= days;
    }
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();

        int low = *max_element(weights.begin(),weights.end());
        int high = accumulate(weights.begin(),weights.end(),0);
        int ans = 0;

        while(low <= high){
            int mid =(low + high)/2;

            if(canweship(weights,days,mid)){
                ans = mid;
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return ans;
    }
};