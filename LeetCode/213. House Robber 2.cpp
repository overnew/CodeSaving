//https://leetcode.com/problems/house-robber-ii/
class Solution {
public:
    static int FindMax(vector<int> &nums, int start, int end) {
        int prev1=0, prev2=0, now=0;

        for (int idx = start; idx<=end; idx++) {
            now = max(prev1, prev2 + nums[idx]);
            prev2 = prev1;
            prev1 = now;
        }
        return now;
    }

    int rob(vector<int>& nums) {
        if (nums.size() == 1)
            return nums[0];

        return max(FindMax(nums, 0, nums.size()-2), FindMax(nums, 1, nums.size() - 1));
    }
};
