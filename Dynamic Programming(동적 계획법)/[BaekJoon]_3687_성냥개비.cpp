//https://www.acmicpc.net/problem/3687
#include<iostream>
#include<vector>
#include<string.h>
using namespace std;
typedef long long ll;

ll dp[101];

void MakeMaxNum(vector<int>& v, int remain_stick) {
	if (remain_stick == 0)
		return;

	if (remain_stick == 3) {
		v.push_back(7);
		return;
	}

	v.push_back(1);
	MakeMaxNum(v, remain_stick-2);
	return;
}

void PrintRev(vector<int>& v) {
	for (int i = v.size() - 1; i >= 0; i--)
		cout << v[i];
}

int main() {
	ios_base::sync_with_stdio(0);
	int test_num;
	cin >> test_num;

	memset(dp, 0x7f , sizeof(dp));
	dp[1] = 9; dp[2] = 1; dp[3] = 7; dp[4] = 4; dp[5] = 2; dp[6] = 6; dp[7] = 8;

	int min_num[8] = { 0,0,1,7,4,2,0,8 };

	for (int i= 8; i<=100 ; ++i) {
		for (int j = 2; j<=7 ; ++j) {
			dp[i] = min(dp[i], dp[i-j]*10 + min_num[j]);
		}
	}

	while (test_num--) {
		vector<int> max_v;
		int stick;
		cin >> stick;
		MakeMaxNum(max_v, stick);
		cout << dp[stick] << ' ';
		PrintRev(max_v);
		cout << '\n';
	}

	return 0;
}
