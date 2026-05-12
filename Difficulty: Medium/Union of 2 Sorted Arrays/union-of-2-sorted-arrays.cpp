class Solution {
  public:
    vector<int> findUnion(vector<int> &a, vector<int> &b) {
        // code here
        set<int>st;
        int n = a.size();
        int m = b.size();
        
        for(int i=0;i<n;i++){
            st.insert(a[i]);
        }
        for(int i=0;i<m;i++){
            st.insert(b[i]);
        }
        vector<int>Unionarray(st.begin(),st.end());
        return Unionarray;
    }
};