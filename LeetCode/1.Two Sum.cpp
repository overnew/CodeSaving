class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
		vector<pair<int, int>> arr(nums.size());
		for (int i=0; i<nums.size() ; ++i) 
			arr[i] = {nums[i], i};
		
		sort(arr.begin(), arr.end());
		int left = 0, right = arr.size() - 1;
		int add_num;

		while (1) {
			add_num = arr[left].first + arr[right].first;
			if (add_num > target)
				--right;
			else if (add_num < target)
				++left;
			else
				break;
		}

		return vector<int> {arr[left].second, arr[right].second};
    }
};
