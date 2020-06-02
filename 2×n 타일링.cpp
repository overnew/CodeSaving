//https://www.acmicpc.net/problem/11726
//1부터 구해보다 피보나치 수열임을 발견.

#include<iostream>
using namespace std;

int cache[1001];

int fibo(int n){
  cache[1] = 1;
  cache[2] = 2;
  for(int i=3; i<=n ;++i){
    cache[i] = (cache[i-1] + cache[i-2])%10007;// 나누기를 미리 안해주면 틀림. int오버 플로우 때문인듯
  }

  return cache[n];
}

int main(){
  int n;
  cin >> n;

  cout<<fibo(n)<<endl;;

  return 0;
}
