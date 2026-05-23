class Solution {
	int countstudents(vector<int>&nums, int pages) {
		int n = nums.size();
		int student = 1;
		long long studentpages = 0;
		
		for (int i = 0; i<n; i++) {
			if (studentpages + nums[i] <= pages) {
				studentpages += nums[i];
			}
			else {
				student++;
				studentpages = nums[i];
			}
		}
		return student;
	}
	int findmax(vector<int>&nums) {
		int n = nums.size();
		int maxi = INT_MIN;
		for (int i = 0; i<n; i++) {
			maxi = max(maxi, nums[i]);
		}
		return maxi;
	}
	int findsum(vector<int>&nums) {
		int n = nums.size();
		int sum = 0;
		for (int i = 0; i<n; i++) {
			sum += nums[i];
		}
		return sum;
	}
	public:
	int findPages(vector<int> &nums, int k) {
		// code here
		int n = nums.size();
		
		if(k > n){
		    return -1;
		}
		int low = findmax(nums);
		int high = findsum(nums);
		
		while (low <= high) {
			int mid = (low + high)/2;
			
			long long student = countstudents(nums, mid);
			if (student > k) {
				low = mid + 1;
			}
			else {
				high = mid - 1;
			}
		}
		return low;
	}
};
