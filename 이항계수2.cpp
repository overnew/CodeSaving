//https://www.acmicpc.net/problem/11051
//생각해보면 10007로 나눈 나머지는 그냥 int 오버플로우를 안 생기게 방지하는 용인듯. 문제를 어렵게 하려는게 아니라
//

#include <iostream>
using namespace std;

int com[1003][1003];

int Combi(int n,int k){
  com[1][0] = 1;
  com[1][1] = 1;

  for(int i=2 ; i<=n ; ++i){
    com[i][0] =1 ; com[i][n] = 1;
    for(int j= 1 ; j<n ;++j){
      com[i][j] = (com[i-1][j-1] + com[i-1][j])%10007;
    }
  }
  return com[n][k];
}

int main() {
  int n, k;
  cin>> n >> k;

  cout<< Combi(n, k)<<endl;

  return 0;
}
