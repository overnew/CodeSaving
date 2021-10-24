//https://leetcode.com/problems/longest-common-subsequence/
class Solution{
public:
    int longestCommonSubsequence(string text1, string text2) {
        int text1_len = text1.length(), text2_len = text2.length();
        vector<vector<int>> dp(text1.length()+1, vector<int>(text2.length()+1,0));
        text1 = '0' + text1; 
        text2 = '0' + text2;

        for (int i = 1; i<= text1_len; ++i) {
            for (int j= 1; j <=text2_len ; ++j) {
                if (text1[i] == text2[j])
                    dp[i][j] = dp[i-1][j-1] + 1;
                else 
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }

        return dp[text1_len][text2_len];
    }
};
