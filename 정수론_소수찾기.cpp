//https://www.acmicpc.net/problem/1978
//에라스토테네스의 체를 사용. 소수를 미리 메모이제이션

#include <iostream>
#include <string.h>
using namespace std;

int main() {
  int num[100];
  bool prime[1001];
  int n;
  int count =0;
  cin >> n;

  memset(prime, true, sizeof(prime));

  for(int i=0; i<n ; ++i){
    cin>>num[i];
  }

  prime[0] = prime[1] = false; //0과 1은 소수가 아님

  for(int i=2; i<=1000 ; ++i){
    if(prime[i])
      for(int j=i*i ; j<=1000 ;j +=i) //i*i부터 시작하는 이유는 2*i, 3*i, 4*i... (i-1)*i 는 이미 2,3,4..를 돌면서 제거되어 있음.
        prime[j] = false;
  }

  for(int i=0; i<n ; ++i){
    if(prime[num[i]])
      ++count;
  }

  cout<<count<<endl;
  
  return 0;
}
