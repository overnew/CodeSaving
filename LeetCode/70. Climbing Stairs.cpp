//https://leetcode.com/problems/climbing-stairs/
class Solution {
public:
	int climbStairs(int n) {
		int down2stair = 1, down1stair =1, now_stair =1;
		for (int i = 2; i <= n; ++i) {
			now_stair = down2stair + down1stair;
			down2stair = down1stair;
			down1stair = now_stair;
		}
		return now_stair;
	}
};
