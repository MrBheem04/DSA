class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>>ans(n,vector<int>(n));

        int x = 1;
        int top = 0,bottom = n-1;
        int left = 0,right = n-1;

        while(top <= bottom && left <= right){
            for(int i=left;i<=right;i++){
                ans[top][i] = x++;
            }
            top++;
            for(int i= top;i<=bottom;i++){
                ans[i][right] = x++;
            }
            right--;

            if(top > bottom)break;

            for(int i= right;i>=left;i--){
                ans[bottom][i] = x++;
            }
            bottom--;
            
            if(left > right)break;
            for(int i=bottom;i>=top;i--){
                ans[i][left] = x++;
            }
            left++;
        }
        return ans;
    }
};