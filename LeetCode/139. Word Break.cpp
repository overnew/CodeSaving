//https://leetcode.com/problems/word-break/
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int len = s.length();
        vector<vector<bool>> check(len, vector<bool>(len, false));

        string word;
        int find_pos;
        for (int i=0; i<wordDict.size() ; ++i) {
            word = wordDict[i];
            int start_pos = 0, word_len = word.length(), end_pos;
            while (start_pos < len) {
                find_pos = s.find(word, start_pos);
                if (find_pos == string::npos)
                    break;  //문자열이 없는 경우

                end_pos = find_pos + word_len;
                check[find_pos][end_pos -1] = true;
                start_pos = find_pos + 1;
            }
        } 

        vector<bool> dp(len+1, false);
        dp[len] = true;
        for (int i=len-1; i>=0 ; --i) {
            for (int j= i ;j<len ; ++j) {
                if (check[i][j] && dp[j + 1]) {
                    dp[i] = true;
                    break;
                }
            }
        }
        
        return dp[0];
    }
};
