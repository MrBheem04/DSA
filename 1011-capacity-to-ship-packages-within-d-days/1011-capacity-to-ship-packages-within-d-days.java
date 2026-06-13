class Solution {
    public boolean canweship(int[] weights ,int days,int capacity){
        int n = weights.length;
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
    public int shipWithinDays(int[] weights, int days) {
        int n = weights.length;
        
        int low = Arrays.stream(weights).max().getAsInt();
        int high=Arrays.stream(weights).sum();
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
}