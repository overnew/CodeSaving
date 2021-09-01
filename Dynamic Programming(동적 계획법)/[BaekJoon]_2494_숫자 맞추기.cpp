//https://www.acmicpc.net/problem/2494
#include<iostream>
#include<string.h>
#include<string>
using namespace std;

typedef struct state {
	int total_turn = -1;	//전체 회전횟수
	int turn = 0;			//이번 나사에서의 회전
}State;

State dp[10000][10];	//[숫자나사][현재의 수]
char init[10000], dest[10000];
int screw_num;
const int MOD = 10;

int TurnScrew(int left_turned, int idx) {
	if (idx == screw_num)
		return 0;

	int num = init[idx] + left_turned;
	num %= MOD;

	int& ret = dp[idx][num].total_turn;
	if (ret != -1)
		return ret;

	int right; //오른쪽으로 돌려야하는 횟수
	if (dest[idx] > num)
		right = num + 10 - dest[idx];
	else
		right = num - dest[idx];

	int left; //왼쪽으로 돌려야하는 횟수
	if (dest[idx] >= num)
		left = dest[idx] - num;
	else
		left = dest[idx] + 10 - num;

	int left_num = TurnScrew((left_turned + left) % MOD, idx + 1) + left;
	int right_num = TurnScrew(left_turned, idx + 1) + right;
	
	if (left_num < right_num) {	//더 조금 돌려도 되는 것이 최적해가 된다.
		ret = left_num;
		dp[idx][num].turn = left;
	}
	else {
		ret = right_num;
		dp[idx][num].turn = -right;
	}

	return ret;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin >> screw_num;

	string init_state, dest_state;
	cin >> init_state >> dest_state;

	for (int i = 0; i < screw_num; ++i) {
		init[i] = init_state[i] - '0';
		dest[i] = dest_state[i] - '0';
	}

	cout << TurnScrew(0, 0) << '\n';

	int idx = 0, num = init[0], total_left = 0;
	while (1) {	//저장된 최적해를 역추적하자.
		cout << idx + 1 << ' ' << dp[idx][num].turn << '\n';
		if (dp[idx][num].turn > 0) {
			total_left += dp[idx][num].turn;
			total_left %= MOD;
		}
		idx++;
		if (idx == screw_num)
			break;
		num = (init[idx] + total_left) % MOD;
	}

	return 0;
}
