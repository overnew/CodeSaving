//https://leetcode.com/problems/search-in-rotated-sorted-array/
class Solution {
public:
	int search(vector<int>& nums, int target) {
		const int len = nums.size();
		int left = 0, right = len - 1, mid;

		while (1) {
			if (nums[left] > nums[right]) {
				mid = (right + left) / 2;

				if (nums[left] > nums[mid])
					right = mid;
				else
					left = mid + 1;
			}
			else
				break;
		}
		
		int range_len = len, answer =-1;
		right = (left - 1 + len) % len;
		int check_l =0, check_r = len-1, check_mid;

		while (1) {
			mid = (range_len / 2 + left) % len;
			check_mid = (check_r + check_l +1) / 2;

			if (nums[mid] < target) {
				left = (mid+1) % len;
				check_l = check_mid + 1;
			}
			else if(nums[mid] > target){
				right = (mid + len - 1) % len;
				check_r = check_mid - 1;
			}
			else {
				answer = mid;
				break;
			}

			if (check_l > check_r)
				break;

			range_len = (right + len - left+ 1) % len;
		}
		return answer;
	}
};
