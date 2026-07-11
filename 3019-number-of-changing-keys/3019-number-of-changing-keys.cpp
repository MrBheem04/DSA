class Solution {
public:
    int countKeyChanges(string s) {
        int count = 0;
        int n = s.size();
        for(int i=1;i<n;i++){
            if(toupper(s[i]) != toupper(s[i-1])){
                count++;
            }
        }
        return count;
    }
};