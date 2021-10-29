//https://leetcode.com/problems/house-robber/
class Solution {
public:
    int rob(vector<int>& nums) {
        int prev1, prev2, now;
        prev2 = nums[0];

        if (nums.size() == 1)
            return prev2;

        now = prev1 = max(nums[0], nums[1]);
        for (int idx = 2; idx < nums.size(); ++idx) {
            now = max(prev1, prev2 + nums[idx]);
            prev2 = prev1;
            prev1 = now;
        }
        
        return now;
    }
};
