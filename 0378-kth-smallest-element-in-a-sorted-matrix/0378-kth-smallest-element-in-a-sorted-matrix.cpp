class Solution {
public:
    int countLessEqual(vector<int>&row,int x){
        int low = 0;
        int high = row.size()-1;

        while(low <= high){
            int mid = low + (high - low) / 2;

            if(row[mid] > x){
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return low;
    }
    int kthSmallest(vector<vector<int>>& matrix, int k) {

        if(matrix.size() <= 1)return matrix[0][0];
        int n = matrix.size();

        int low = matrix[0][0];
        int high = matrix[n-1][n-1];

        while(low <= high){
            long long mid = low + (high - low)/2;

            int totalcnt = 0;

            for(auto row : matrix){
                totalcnt += countLessEqual(row,mid);
            }
            if(totalcnt < k){
                low = mid + 1; 
            }
            else{
                high = mid-1;
            }
        }
        return low;
    }
};