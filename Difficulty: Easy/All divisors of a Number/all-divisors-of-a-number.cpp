class Solution {
	public:
	vector<int> getDivisors(int n) {
		// code here
		vector<int>res;
		
		for (int i = 1; i* i <= n; i++) {
			if (n % i == 0) {
				res.push_back(i);
				
				if (i != n / i) {
					res.push_back(n/i);
				}
			}
		}
		sort(res.begin(),res.end());
		return res;
	}
};
