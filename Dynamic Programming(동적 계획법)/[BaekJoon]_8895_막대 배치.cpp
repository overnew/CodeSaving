//https://www.acmicpc.net/problem/8895
#include<iostream>
#include<string.h>
using namespace std;

typedef long long  ll;
ll dp[21][21][21];

int main(){
  ios_base::sync_with_stdio(0);
  memset(dp, 0 ,sizeof(dp));
  dp[1][1][1] = 1;

  for(int stick = 2; stick<=20 ; ++stick)
    for(int l = 1; l<=stick ; ++l)
      for(int r = 1; r<=stick ; ++r)
        dp[stick][l][r] = dp[stick-1][l-1][r] + dp[stick-1][l][r-1] + dp[stick-1][l][r] * (stick -2);
      
  int test_num;
  cin>>test_num;

  int stick_num, left, right;
  while(test_num--){
    cin>>stick_num>>left>>right;
    cout<<dp[stick_num][left][right]<<'\n';
  }

  return 0;
}
