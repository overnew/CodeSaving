#include<stdio.h>
#include<iostream>
#include<math.h>
#include<cmath>
#include<sstream>
#include<string>
#include<map>
#include<cstring>
using namespace std;

int N, S;
int arr[40];
int half_idx = -1;
long result_cnt = 0;
map<int, int> sum_map;

void makeLeftSubSetSum(int target_idx, int sum) {
	if (target_idx == half_idx) {
		++sum_map[sum];
		return;
	}

	makeLeftSubSetSum(target_idx+1, sum + arr[target_idx]);
	makeLeftSubSetSum(target_idx+1, sum);
}

void makeWithCheckRightSubSetSum(int target_idx, int sum) {
	if (target_idx == N) {
		result_cnt += sum_map[S - sum];
		return;
	}

	makeWithCheckRightSubSetSum(target_idx + 1, sum + arr[target_idx]);
	makeWithCheckRightSubSetSum(target_idx + 1, sum);
}


int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> N >> S;
	for (int i = 0; i < N; i++)
		cin >> arr[i];
	
	half_idx = N / 2;

	makeLeftSubSetSum(0,0);
	makeWithCheckRightSubSetSum(half_idx,0);

	if (S == 0)
		--result_cnt;

	cout << result_cnt;

	return 0;
}
