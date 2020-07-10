//https://www.acmicpc.net/problem/2003
// 간단한 투 포인터스 문제

#include<iostream>
using namespace std;

int arr[10000];

int main() {
	int n, m;
	int r = 0, l = 0,sum =0, count=0;

	cin >> n >> m;
	for (int i=0; i<n ;++i) {
		cin >> arr[i];
	}

	sum = arr[0];
	while (l<=r && r<n) {
		if (sum < m) {
			sum += arr[++r];
		}
		else if (sum == m) {
			++count;
			sum += arr[++r];
		}
		else if (sum > m) {
			sum -= arr[l++]; //left은 후위로 ++인거 잊지 말자!
			if (l > r && l<n) 
				sum += arr[++r]; //l이 r을 넘는 경우를 처리 안해줘서 계속 틀림
		}
	}

	cout << count << endl;

	return 0;
}
