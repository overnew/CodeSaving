//https://www.acmicpc.net/problem/1929
//에라스토테네스의 체로 최적화하지 못하면 시간초과가 발생하는 문제.

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <cmath> // for sqrt
using namespace std;

int main() {
  bool prime[1000001];
  int m,n;

  cin >> m >> n;

  int sqrtn = int(sqrt(n)); //n의 제곱근
  memset(prime, true, sizeof(prime));

  prime[0] = prime[1] = false; 

  for(int i=2; i<=sqrtn; ++i){ //n의 제곱근 까지만 구해도 소수가 아니라면 소인수 분해가 가능해야하기 때문에 인수분해시 n의 제곱근이하의 수와 
  // 짝을 지어야만 한다. 따라서 소수를 구할 때는 제곱근까지만 구해도 최적화가 가능하다.
    if(prime[i])
      for(int j=i*i ; j<=n ;j +=i)
        prime[j] = false;
  }

  for(int i=m; i<=n ; ++i){
    if(prime[i])
      printf("%d\n",i);
  }
  
  return 0;
}
