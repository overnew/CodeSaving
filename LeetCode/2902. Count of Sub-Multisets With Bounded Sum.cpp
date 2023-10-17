class Solution {

public:
    int countSubMultisets(vector<int>& nums, int l, int r) {
		const int MOD = 1e9 + 7;
		unordered_map<int, int> cnt;

		int dp[20001];
		memset(dp, 0, sizeof(dp));
		dp[0] = 1;		//빈 set 준비

		for (int num :nums)		//개수 세기
			cnt[num]++;

		int zero_cnt = cnt[0];	
		cnt.erase(0);	//0의 개수는 따로 저장

		int sum_so_far = 0;
		for (unordered_map<int, int>::iterator it = cnt.begin(); it != cnt.end(); ++it) {
			int value = it->first, value_cnt = it->second;

			sum_so_far += value * value_cnt;

			int start = min(sum_so_far, r);
			for (int i = start; i>= value; --i) {
				for (int j = 1; value_cnt>= j && i - j * value >=0; j++){
					dp[i] += dp[i - j * value];
					if(dp[i] >= MOD)	
						dp[i] -=MOD;
				}
			}
		}

		long long answer =0; 
		for (int i = l; i <= r; ++i) 
			answer = (answer+ dp[i]) %MOD;

		return answer *(cnt[0] +1) %MOD;
    }
};
