//https://www.acmicpc.net/problem/1644
/*
  에라스토테네스의 체+정수론 + 투 포인터
  vector의 할당은 생각보다 저렴하다는 것을 기억하자
*/

#include<iostream>
#include<cmath>
#include<string.h>
#include<vector>
using namespace std;

bool is_prime[4000001];

int main() {
	int n,i,j;
	vector<int> prime;
	cin >> n;

	int sqrtn = int(sqrt(n));
	memset(is_prime, true, sizeof(is_prime));

	is_prime[0] = is_prime[1] = false;

	for (i=2; i<=sqrtn ; ++i) {
		if (is_prime[i]) {
			for (j = i * i; j <= n; j += i)
				is_prime[j] = false;
		}
	}

	for (i=2; i<=n  ; ++i) {
		if (is_prime[i])
			prime.push_back(i);
	}
	prime.push_back(0);

	int r = 0, l = 0;
	int sum = 0, cnt=0;

	sum = prime[0];
	while (l<=r && r<prime.size()-1) { //r이 마지막에 범위를 초과해서 빈 벡터값을 하나 넣어줌
		if (sum < n) {
			sum += prime[++r];
		}
		else if (sum == n) {
			++cnt;
			sum += prime[++r];
		}
		else if(sum >n) {
			sum -= prime[l++];
		}
	}

	cout << cnt << endl;

	return 0;
}
