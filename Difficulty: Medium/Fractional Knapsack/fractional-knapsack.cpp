class Solution {
    struct Item {
        int value;
        int weight;
    };

public:
    static bool comp(Item a, Item b) {
        double r1 = (double)a.value / a.weight;
        double r2 = (double)b.value / b.weight;
        return r1 > r2;
    }

    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
        int n = val.size();

        vector<Item> items(n);

        for (int i = 0; i < n; i++) {
            items[i] = {val[i], wt[i]};
        }

        sort(items.begin(), items.end(), comp);

        int currentWt = 0;
        double finalValue = 0.0;

        for (int i = 0; i < n; i++) {
            if (currentWt + items[i].weight <= capacity) {
                currentWt += items[i].weight;
                finalValue += items[i].value;
            } else {
                int remain = capacity - currentWt;
                finalValue += ((double)items[i].value / items[i].weight) * remain;
                break;
            }
        }

        return finalValue;
    }
};