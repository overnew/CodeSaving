//https://leetcode.com/problems/decode-ways/
class Solution {
public:
    int numDecodings(string s) {
        s = "00" + s;

        vector<int> dp(s.size(), 0);
        dp[0] = dp[1] = 1;

        for (int i=2; i<s.size() ; ++i) {
            if (s[i] != '0') 
                dp[i] += dp[i - 1];
            
            int idx = (int)(s[i - 1] - '0') * 10 + (int)(s[i] - '0');
            if ( 10<= idx && idx <= 26) 
                dp[i] += dp[i-2];
        }
        return dp[s.size() - 1];
    }
};
