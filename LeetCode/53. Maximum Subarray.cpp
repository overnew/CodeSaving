//https://leetcode.com/problems/maximum-subarray/
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
		int sum =0, max_sum = nums[0];

		for (int idx =0; idx< nums.size(); ++idx) {
			sum += nums[idx];
			max_sum = max(max_sum, sum);
			if (sum < 0)
				sum = 0;
		}
		return max_sum;
    }
};
