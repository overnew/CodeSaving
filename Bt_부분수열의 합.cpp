//https://www.acmicpc.net/problem/1182

#include <iostream>
#include <string.h>
using namespace std;

int N,S;
int arr[20];
bool selected[20];
int count =0;

void Recursive(int n,int cnt,int sum,int idx){
  if(cnt == n){
    if(sum == S)
      ++count;
    return;
  }

  for(int i=idx; i<N ; ++i){
    if(!selected[i]){
      selected[i] = true;
      Recursive(n, cnt+1, sum + arr[i], i+1); //i의 다음 부터 접근해야 이전 것들을 또 다시 선택하는 중복을 막을 수 있음
      selected[i] = false;
    }
  }

}

int main() {
  cin>>N>>S;

  for(int i=0; i<N ; ++i)
    cin>>arr[i];
  
  memset(selected, false, sizeof(selected));

  for(int i=1; i<=N ; ++i){
    Recursive(i, 0, 0, 0); //n(수열의 크기)를 1씩 증가시킴
  }

  cout<<count<<'\n';

  return 0;
}
