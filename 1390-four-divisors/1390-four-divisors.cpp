class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int ans = 0;
        for(int num : nums){
            int sum = 0;
            int count = 0;

            for(int  i=1;i<=sqrt(num);i++){
                if(num % i == 0){
                    int d1 = i;
                    int d2 = num/i;
                    if(d1 == d2){
                        count++;
                        sum += d1;
                    }
                    else{
                        count += 2;
                        sum += d1+d2; 
                    }
                }
            } 
            if(count == 4){
                ans += sum;
            }
        }
        return ans;
    }
};