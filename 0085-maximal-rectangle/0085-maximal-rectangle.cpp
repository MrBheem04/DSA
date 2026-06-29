class Solution {
    int largestRectangle(vector<int> & heights){
        stack<int>st;
        int n = heights.size();
        int maxi = 0;

        for(int i=0;i<=n;i++){
            while(!st.empty() &&(i==n || heights[st.top()] >= heights[i])){
                int height = heights[st.top()];
                st.pop();

            int width;
            if(st.empty()){
                width = i;
            }
            else{
                width = i-st.top()-1;
            }
            maxi = max(maxi,width*height);
            }
            st.push(i);
        }
        return maxi;
    }
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.empty())return 0;

        int n = matrix[0].size();
        vector<int>heights(n,0);

        int maxArea = 0;

        for(auto &row : matrix){
            for(int i=0;i<n;i++){
                if(row[i] == '1')heights[i]++;
                else heights[i] = 0;
            }
            maxArea = max(maxArea , largestRectangle(heights));
        }
        return maxArea;
    }
};