class Solution {
  public:
    int kthElement(vector<int> &a, vector<int> &b, int k) {
        // code here
        int n1 = a.size();
        int n2 = b.size();
        
        int count = 0;
        int i=0,j=0;
        while(i< n1 && j < n2){
            if(a[i] < b[j]){
                if(count == k-1) return a[i];
                count++;
                i++;
            }
            else{
                if(count == k-1)return b[j];
                count++;
                j++;
            }
        }
        while(i < n1){
            if(count == k-1)return a[i];
            count++;
            i++;
        }
        while(j < n2){
            if(count == k-1)return b[j];
            count++;
            j++;
        }
        return -1;
    }
};