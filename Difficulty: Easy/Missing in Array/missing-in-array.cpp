class Solution {
  public:
    int missingNum(vector<int>& arr) {
        // code here
        int n = arr.size()+1;
        long long s1=0,s2=(1ll*n*(n+1))/2;
        for(int i=0;i<n-1;i++){
            s1+=arr[i];
        }
        return s2-s1;
    }
};