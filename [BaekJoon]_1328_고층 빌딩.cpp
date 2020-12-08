//https://www.acmicpc.net/problem/1328
#include <iostream>
#include<string.h>
using namespace std;

int building_num;
int left_num, right_num;
const int mod = 1000000007;
int dp[101][101][101];

int main() {
  cin>>building_num>>left_num>>right_num;

  memset(dp, 0, sizeof(dp));

  dp[1][1][1] =1;

  for(int idx=2; idx<=building_num ; ++idx)
    for(int l =1 ; l<=idx ; ++l)
      for(int r=1; r<=idx ; ++r)
        dp[idx][l][r] = ((long long)dp[idx-1][l][r]*(idx-2) + dp[idx-1][l-1][r] + dp[idx-1][l][r-1])%mod;

  cout<<dp[building_num][left_num][right_num]<<'\n';
  return 0;
}
