//https://leetcode.com/problems/maximum-product-subarray/submissions/
class Solution {
public:
    int maxProduct(vector<int>& nums) {
		int max_prod = nums[0], len = nums.size();
		int left_prod =1, right_prod =1;

		for (int i=0; i<len ; ++i) {
			left_prod *= nums[i];
			max_prod = max(max_prod, left_prod);
			if (nums[i] == 0)
				left_prod = 1;
		}

		for (int i = len -1; i>=0; --i) {
			right_prod *= nums[i];
			max_prod = max(max_prod, right_prod);
			if (nums[i] == 0)
				right_prod = 1;
		}

		return max_prod;
    }
};
