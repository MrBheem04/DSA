class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        
        int maxcost = *max_element(costs.begin(),costs.end());

        int n = costs.size();
        vector<int>freq(maxcost + 1,0);

        for(int i=0;i<n;i++){
            freq[costs[i]]++;
        }
        int ans = 0;

        for(int i=1;i<=maxcost;i++){
            if(freq[i] == 0){
                continue;
            }

            int canBuy = min(freq[i],coins/i);
            ans += canBuy;
            coins -= canBuy * i;

            if(coins < i){
                break;
            }
        }
        return ans;
    }
};