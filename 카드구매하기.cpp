//https://www.acmicpc.net/problem/11052
//첫시도는 21_line의 i>=(n/2)에서 등호를 빼먹음.. 아쉽게시리
// n개의 카드 최대값은  [n-1]+1, [n-2]+[2], ... [n-(n/2)]+[n/2]중 최대를 찾으면 구할 수 있다!

#include <iostream>
#include <string>
#include <string.h>
using namespace std;

int N;
int pack[10001];
int cache[10001];

int CardCollect(int n){
  int max=0;
  int temp;
  if(n==1) return pack[1];

  int& ret = cache[n];
  if(ret != -1) return ret;

  for(int i=n-1; i>=(n/2) ; --i){
    temp =(CardCollect(i) +CardCollect(n-i) );
    max = max > temp ? max : temp;
  }

  ret = max > pack[n] ? max : pack[n];
  return ret;
}

int main() {
  cin>>N;

  for(int i=1; i<=N; ++i){
    cin>>pack[i];
  }
  memset(cache, -1, sizeof(cache));

  cout<<CardCollect(N)<<endl;

  return 0;
}
