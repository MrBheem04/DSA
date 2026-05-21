class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        int len = 0;

        int n = arr1.size();
        int m = arr2.size();

        unordered_set<int> st1;

        for (int i = 0; i < n; i++) {
            int num = arr1[i];

            while (num > 0) {
                st1.insert(num);
                num = num / 10;
            }
        }
        unordered_set<int> st2;

        for (int i = 0; i <m ; i++) {
            int num = arr2[i];

            while(num > 0){
                st2.insert(num);
                num = num / 10;
            }
        }

        vector<int>a(st1.begin(),st1.end());
        vector<int>b(st2.begin(),st2.end());

        for(int i=0;i<a.size();i++){
            int num = a[i];

            string temp = to_string(num);

            int c = temp.size();

            if(st2.count(num)){
            len = max(len , c);
            }
        }

        for(int i=0;i<b.size();i++){
            int num = b[i];

            string temp = to_string(num);

            int c = temp.size();

            if(st1.count(num)){
                len = max(len,c);
            }
        }
        return len;
    }
};