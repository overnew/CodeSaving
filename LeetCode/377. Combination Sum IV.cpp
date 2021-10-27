//https://leetcode.com/problems/combination-sum-iv/
class Solution {
public:
    static const int MOD = INT32_MAX;

    int combinationSum4(vector<int>& nums, int target) {
        vector<long long> dp(target + 1, 0);
        sort(nums.begin(), nums.end());

        dp[0] = 1;
        for (int value =1 ; value<= target; ++value) {
            for (int idx =0; idx< nums.size() && nums[idx] <= value ; ++idx)
                dp[value] += dp[value - nums[idx]];
            dp[value] %= MOD;
        }
        return dp[target];
    }
};
