//https://leetcode.com/problems/jump-game/
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int idx = 0;
        for (int reached =0; idx<nums.size() && idx<=reached ; ++idx) {
            reached = max( idx+ nums[idx], reached);
        }
        return idx == nums.size();
    }
};
