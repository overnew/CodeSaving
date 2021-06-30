//https://www.acmicpc.net/problem/10251
#include<iostream>
#include<string.h>
using namespace std;

int row, column, drive_time, init_fuel;
int right_cost[100][100], down_cost[100][100];
int dp[100][100][200][2];

int main(){
  ios_base::sync_with_stdio(0);
  int test_num;
  cin>>test_num;

  while(test_num--){
    cin>>row>>column>>drive_time>>init_fuel;

    for(int r=0; r<row ; ++r)
      for(int c=0; c<column-1 ; ++c)
        cin>>right_cost[r][c];

    for(int r=0; r < row-1 ; ++r)
      for(int c=0; c<column ; ++c)
        cin>>down_cost[r][c];

    memset(dp, 0x3f ,sizeof(dp));
    dp[0][0][0][0] = dp[0][0][0][1] = 0;

    for(int r=0; r<row ; ++r)
      for(int c=0; c<column ; ++c)
        for(int turn=0; turn < 200 ; ++turn){
          //오른쪽은 dir: 0
          if(c+1<column){
            dp[r][c+1][turn][0] = min(dp[r][c+1][turn][0], dp[r][c][turn][0] + right_cost[r][c]);
            dp[r][c+1][turn+1][0] = min(dp[r][c+1][turn+1][0], dp[r][c][turn][1] + right_cost[r][c]);
          }

          //아래쪽은 dir1
          if(r+1< row){
            dp[r+1][c][turn][1] = min(dp[r+1][c][turn][1], dp[r][c][turn][1] + down_cost[r][c]);
            dp[r+1][c][turn+1][1] = min(dp[r+1][c][turn+1][1], dp[r][c][turn][0] + down_cost[r][c]);
          }

        }
    
    //최소 방향 전환 횟수를 찾자
    int min_turn = 200;
    for(int i=0; i<200 ; ++i){
      if(dp[row-1][column-1][i][0]<=init_fuel ||dp[row-1][column-1][i][1]<=init_fuel)
        min_turn = min(min_turn, i);
    }

    if(min_turn == 200)
      cout<<-1<<'\n';
    else 
      cout<<min_turn + (row + column -2) * drive_time<<'\n';
  } 

  return 0;
}
