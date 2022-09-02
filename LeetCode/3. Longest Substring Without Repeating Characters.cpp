class Solution {
private:
	int minDistanceFromSameChar[50001];

public:
	int lengthOfLongestSubstring(string s) {
		memset(minDistanceFromSameChar, -1, sizeof(minDistanceFromSameChar));

		for (int idx =0; idx<s.length(); ++idx)   //초기화
			for (int dist = 1; dist + idx < s.length(); ++dist) 
				if (s[idx] == s[dist + idx]) {
					minDistanceFromSameChar[idx] = dist;
					break;
				}
			

		int maxLen = 0; 
		for (int idx = 0; idx < s.length(); ++idx) {  //구하기 시작
			int maxLenStartWithIdx = minDistanceFromSameChar[idx];

			if (maxLenStartWithIdx == -1)
				maxLenStartWithIdx = s.length() - idx;

			for (int dist = 1; dist < maxLenStartWithIdx; ++dist) {
				if (minDistanceFromSameChar[dist + idx] == -1)
					continue;
				if (minDistanceFromSameChar[dist + idx] + dist < maxLenStartWithIdx)
					maxLenStartWithIdx = minDistanceFromSameChar[dist + idx] + dist;
			}

			maxLen = max(maxLen, maxLenStartWithIdx);
		}

		return maxLen;
	}
};
