class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
		int length = nums.size();
		vector<int> answer(length, 1);

		for (int left = 1; left< length; ++left ) {
			answer[left] *= nums[left-1];
			answer[left] *= answer[left -1];
		}

		int right_prod = 1;
		for (int right = length - 2; right >=0 ; --right) {
			answer[right] *= nums[right + 1];
			answer[right] *= right_prod;
			right_prod *= nums[right + 1];
		}

		return answer;
    }
};
