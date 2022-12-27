class Solution {
private:
    int dp[1000][1000];
    
public:
    string longestPalindrome(string s) {
        memset(dp, 0, sizeof(dp));

        string answer = s.substr(0,1);
        for (int start = s.length()-1; start>=0 ; --start ) {
            dp[start][start] = 1;

            for (int end = start +1; end <s.length(); ++end) {
                if (s[start] == s[end]) {
                    if (start == (end - 1)) {
                        dp[start][end] = 2;

                        if (answer.length() < (end - start + 1)) 
                            answer = s.substr(start, 2);
                        
                    }else if (dp[start + 1][end - 1] != 0) {
                        dp[start][end] = dp[start + 1][end - 1] + 2;

                        if (answer.length() < (end - start + 1)) 
                            answer = s.substr(start, end - start + 1);
                        
                    }
                }
            }
        }

        return answer;
    }
};
