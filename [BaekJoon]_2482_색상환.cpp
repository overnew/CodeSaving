//https://www.acmicpc.net/problem/2482
#include <iostream>
using namespace std;

int color_num, select_num;
const int mod = 1000000003;
int dp[1001][1001];

int main() {
  cin>>color_num>>select_num;

  for(int i=0; i<color_num ; ++i){
    dp[i][0] =1;
    dp[i][1] = i;
  }
    
  for(int idx=2; idx<=color_num; ++idx)
    for(int k=2 ; k<=select_num ; ++k)
      dp[idx][k] = (dp[idx-2][k-1] + dp[idx-1][k])%mod;

  cout<<(dp[color_num-1][select_num]+ dp[color_num-3][select_num-1])%mod<<'\n';
  
  return 0;
}
