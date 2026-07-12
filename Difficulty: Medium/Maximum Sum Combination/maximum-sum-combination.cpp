class Solution {
  public:
    vector<int> topKSumPairs(vector<int>& a, vector<int>& b, int k) {
        // code here
        sort(a.begin(),a.end(),greater<>());
        sort(b.begin(), b.end(),greater<>());
        
        priority_queue<tuple<int,int,int>>maxHeap;
        set<pair<int,int>>visited;
        
        maxHeap.push({a[0] + b[0] , 0 , 0});
        visited.insert({0,0});
        
        vector<int>result;
        
        while(k-- && !maxHeap.empty()){
            auto[sum,i,j] = maxHeap.top();
            maxHeap.pop();
            
            result.push_back(sum);
            
            if(i+1 < a.size() && !visited.count({i+1, j})){
                maxHeap.push({a[i + 1] + b[j],i+1,j});
                visited.insert({i+1 ,j});
            }
            if(j+1 < b.size() && !visited.count({i,j+1})){
                maxHeap.push({a[i] + b[j+1],i,j+1});
                visited.insert({i,j+1});
            }
        }
        return result;
    }
};