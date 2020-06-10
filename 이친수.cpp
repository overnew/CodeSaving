//https://www.acmicpc.net/problem/2193
//피보임을 파악하는 것 까진 좋았는데 n=47부터 int \의 범위를 초과함.. long을 사용해야됨. 이런걸 조심하자

#include <iostream>
using namespace std;

long pibo[94];

long Pi_number(int n){
  pibo[1] = 1;
  pibo[2] = 1;

  for(int i=3; i<=n ; ++i){
    pibo[i] = pibo[i-1] + pibo[i-2];
  }
  return pibo[n];
}

int main() {
  int n; 
  cin>> n;

  cout<<Pi_number(n)<<endl;

  return 0;
}
