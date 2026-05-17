class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>ans;

        for(int i=0;i<numRows;i++){
            long long val =1;

            vector<int>ansRow;

            for(int col =0;col<=i;col++){
                ansRow.push_back(val);
                val = val * (i-col)/(col + 1);
            }
            ans.push_back(ansRow);
        }
        return ans;
    }
};