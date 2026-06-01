class Solution {
public:
    int minimumCost(vector<int>& cost) {
        int n = cost.size();
        sort(cost.begin(),cost.end());
        int ans = 0;
        int count = 0;

        for(int i=n-1;i>=0;i--){
            count++;
            if(count % 3 != 0){
                ans += cost[i];
            }
        }
        return ans;
    }
};