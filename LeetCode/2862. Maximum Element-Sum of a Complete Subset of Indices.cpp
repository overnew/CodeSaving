class Solution {
public:
	long long maximumSum(vector<int>& nums) {

		long long maxSum = 0;
		for (int base =1; base <= nums.size(); ++base) {

			long long stackSum = 0;
			for (int var = 1; var * var * base <= nums.size(); ++var) 
				maxSum = max(maxSum, stackSum += nums[(var * var * base) - 1]);
			
		}

		return maxSum;
	}
};
