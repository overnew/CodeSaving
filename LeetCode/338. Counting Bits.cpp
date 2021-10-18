//https://leetcode.com/problems/counting-bits/
class Solution {
public:
	vector<int> countBits(int n) {
		vector<int> dp(n+1);
		dp[0] = 0;

		int copy_len = 1, next_idx;
		for (; copy_len <= n; copy_len *= 2) {
			for (int idx = 0; idx < copy_len  ; ++idx ) {
				next_idx = idx + copy_len;
				if (next_idx > n)
					break;
				dp[idx + copy_len] = 1 + dp[idx];
			}
		}
		return dp;
	}
};
