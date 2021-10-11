//https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/
class Solution {
public:
    int findMin(vector<int>& nums) {
		int left = 0, right = nums.size() - 1;
		int mid;

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
		return  nums[left];
    }
};
