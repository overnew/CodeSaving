//https://www.acmicpc.net/problem/2133
/*
  특이 케이스를 반영해서 점화식을 구하면 다음과 같다.
  cache[i] = cache[i - 2] * 3;
  for (int j=4; j<=i; j+=2) {
		cache[i] += cache[i-j]*2; 특이 케이스인 2가지를 나머지들과 결합해줌
	}
*/

#include<iostream>
using namespace std;

int cache[31];

int main() {
	int n;
	cin >> n;

	cache[0] = 1;
	cache[2] = 3;

	if (n % 2 == 1) cout << 0 << endl;
	else {
		for (int i=4; i<=n ; i+=2) {
			cache[i] = cache[i - 2] * 3;
			for (int j=4; j<=i; j+=2) {
				cache[i] += cache[i-j]*2;
			}
		}

		cout << cache[n] << endl;
	}

	return 0;
}
