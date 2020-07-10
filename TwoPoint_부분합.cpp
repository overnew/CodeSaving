//https://www.acmicpc.net/problem/1806
/*
	
*/

#include<iostream>
using namespace std;

int sump[100000];

int main() {
	int n,s;
	cin>>n >> s;

	sump[0] = 0; //부분합 계산에 용이 하도록! 배열의 첫 값 =sump[1] -sump[0]
	for (int i=1; i<=n ; ++i) {
		cin >> sump[i];
		sump[i] += sump[i - 1];
	}

	for (int i=1; i<=n ; ++i) { //i는 배열의 길이
		for (int j=i ; j<=n ; ++j) {
			if (sump[j] - sump[j - i] >= s) {
				cout << i << endl;
				return 0;
			}
		}
	}

	cout << 0 << endl;

	return 0;
}

//부분합으로 단순히 푸는 법과 투포인터스(left,right)로 푸는 두가지 경우

