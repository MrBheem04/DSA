class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {

        unordered_map<char, int> freq;
        for (char task : tasks) {
            freq[task]++;
        }

        priority_queue<int> maxHeap;
        for (auto& entry : freq) {
            maxHeap.push(entry.second);
        }
        int time = 0;

        while (!maxHeap.empty()) {
            vector<int> temp;
            int cycle = n + 1;
            int i = 0;

            while (i < cycle && !maxHeap.empty()) {

                int count = maxHeap.top();
                maxHeap.pop();
                count--;

                if (count > 0) {
                    temp.push_back(count);
                }
                time++;
                i++;
            }
            for (int val : temp) {
                maxHeap.push(val);
            }
            if(maxHeap.empty())break;

            time +=(cycle-i);
        }
        return time;
    }
};