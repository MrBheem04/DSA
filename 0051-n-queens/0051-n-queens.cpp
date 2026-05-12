class Solution {
    public:
    void solve(int col,vector<string>&board,vector<vector<string>>&ans,vector<int>&leftRow,vector<int>&lowerDigonal,vector<int>&upperDigonal, int n){
        if(col == n){
            ans.push_back(board);
            return;
        }
        for(int row = 0;row<n;row++){
            if(leftRow[row] == 0 && lowerDigonal[row+col] == 0 && upperDigonal[n-1+col-row] == 0){
                board[row][col] ='Q';
                leftRow[row] = 1;
                lowerDigonal[row+col] = 1;
                upperDigonal[n-1+col-row] = 1;
                solve(col+1,board,ans,leftRow,lowerDigonal,upperDigonal,n);
                board[row][col] ='.';
                leftRow[row] = 0;
                lowerDigonal[row+col] = 0;
                upperDigonal[n-1+col-row] = 0;
            }
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
        vector<string>board(n,string(n,'.'));

        vector<int>leftRow(n,0),lowerDigonal(2*n-1,0),upperDigonal(2*n-1,0);
        solve(0,board,ans,leftRow,lowerDigonal,upperDigonal,n);
        return ans;        
    }
};