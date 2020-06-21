https://www.acmicpc.net/problem/11399
//쉬운 그리디 알고리즘. 가장 빨리 인출하는 사람이 먼저 할수록 시간합이 최소가 됨.

#include <iostream>
#include <algorithm>
using namespace std;

int draw[1000];

int main() {
  int n;
  int sum =0;
  cin >> n;

  for(int i=0; i<n ; ++i){
    cin>>draw[i];
  }

  sort(draw, draw+n);

  for(int i= 0 ; i<n ;++i ){
    sum+= draw[i]*(n-i);
  }

  cout<< sum<<endl;

  return 0;
}
