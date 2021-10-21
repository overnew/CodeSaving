//https://leetcode.com/problems/coin-change/
class Solution {
public:
	int coinChange(vector<int>& coins, int amount) {
		vector<int> dp(amount+1, 10001);
		int len = coins.size();
		dp[0] = 0;

		for (int value =1; value <=amount ; ++value) 
			for (int i = 0; i< len; ++i) 
				if (value - coins[i] >= 0)
					dp[value] = min(dp[value], dp[value - coins[i]] +1);
			
		if (dp[amount] == 10001)
			return -1;
		return dp[amount];
	}
};
