class Solution {
	public:
	int canweplace(vector<int>&stalls, int cows, int d) {
		int n = stalls.size();
		int count = 1;
		int lastpos = stalls[0];
		
		for (int i = 0; i<n; i++) {
			if (stalls[i] - lastpos >= d) {
				count++;
				lastpos = stalls[i];
			}
			if (count >= cows)return true;
		}
		return false;
	}
	int aggressiveCows(vector<int> &stalls, int k) {
		// code here
		int n = stalls.size();
		sort(stalls.begin(),stalls.end());
		int low = 1;
		int high = stalls[n-1]-stalls[0];
		int ans = 0;
		
		while(low <= high){
		    int mid =(low + high)/2;
		    
		    if(canweplace(stalls,k,mid)){
		        ans = mid;
		        low = mid+1;
		    }
		    else{
		        high = mid-1;
		    }
		}
		return ans;
	}
};
