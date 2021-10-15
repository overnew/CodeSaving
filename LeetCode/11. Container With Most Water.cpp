//https://leetcode.com/problems/container-with-most-water/
class Solution {
public:
	static bool compare(const pair<int,int>& a, const pair<int, int>& b) {
		if (a.first == b.first)
			return a.second < b.second;
		return a.first > b.first;
	}

	int maxArea(vector<int>& height) {
		const int len = height.size();
		vector<pair<int, int>> height_sort(len);

		for (int i=0; i<len ; ++i) 
			height_sort[i] = {height[i], i};

		sort(height_sort.begin(), height_sort.end(), compare);

		int left_height = height_sort[0].first, left_pos = height_sort[0].second;
		int right_height = height_sort[1].first, right_pos = height_sort[1].second;
		
		if (right_pos < left_pos) {//left가 right보다 오른쪽에 있다면 swap해주자
			swap(left_height, right_height);
			swap(left_pos, right_pos);
		}

		int max_width = abs(right_pos - left_pos) * min(left_height, right_height);
		int next_height, next_pos;

		for (int idx =2; idx <len ; ++idx) {
			next_height = height_sort[idx].first;
			next_pos = height_sort[idx].second;

			if (next_pos < left_pos) {
				left_pos = next_pos;
				left_height = next_height;
			}
			else if (right_pos < next_pos) {
				right_pos = next_pos;
				right_height = next_height;
			}//이외의 경우는 영향x

			max_width = max(max_width, abs(right_pos - left_pos)*min(left_height, right_height));
		}
		return max_width;
	}
};
