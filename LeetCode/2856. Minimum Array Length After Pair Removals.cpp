class Solution {
public:
	int minLengthAfterRemovals(vector<int>& nums) {
		unordered_map<int, int> cnt_map;

		for (vector<int>::iterator it = nums.begin(); it != nums.end(); ++it)
			cnt_map[*it] += 1;
		 
		int max_cnt = 0;
		for (unordered_map<int, int>::iterator it = cnt_map.begin(); it != cnt_map.end(); ++it) {
			max_cnt = max(max_cnt, it->second);
		}

		if (max_cnt > (nums.size() / 2)) {
			return 2 * max_cnt - nums.size();
		}

		if (nums.size() % 2) {	//나머지 1
			return 1;
		}
		
		return 0; //나머지 0
	}
};
