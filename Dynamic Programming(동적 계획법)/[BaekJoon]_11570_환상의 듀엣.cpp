//https://www.acmicpc.net/problem/11570
#include<iostream>
#include<string.h>
#include<math.h>
using namespace std;

int tune_num;
int tune[2001];
int dp[2001][2001];

int main(){
  ios_base::sync_with_stdio(0);
  cin>>tune_num;

  for(int i=1; i<=tune_num ; ++i)
    cin>>tune[i];
  
  memset(dp, 0x7f , sizeof(dp));
  dp[0][1] = dp[1][0] = 0;

  for(int i=0; i<=tune_num ; ++i){
    for(int j=0 ; j<=tune_num ; ++j){
      if(i==j)
        continue;

      int next = max(i, j)+1;
      if(next >tune_num)
        continue;
      
      if(i==0 || j==1)
        tune[0] = tune[next];

      dp[next][j] = min(dp[next][j], dp[i][j] + abs(tune[i] - tune[next]));
      dp[i][next] = min(dp[i][next], dp[i][j] + abs(tune[j] - tune[next]));
    }
  }

  int min_answer = INT32_MAX;

  for(int i=0; i<=tune_num ; ++i){
    min_answer = min(min_answer, dp[i][tune_num]);
    min_answer = min(min_answer, dp[tune_num][i]);
  }

  cout<<min_answer<<'\n';
  return 0;
}
