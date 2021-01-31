//https://www.acmicpc.net/problem/3190
#include <iostream>
#include<queue>
#include<string.h>
using namespace std;

int board_size,apple_num,turn_num;
bool is_apple[101][101];
bool is_snake[101][101];
pair<int,char> turn[101];
int move_next[4][2] ={{0,1},{1,0},{0,-1},{-1,0}};

int PlayGame(){
  int time =0, direction =0,idx =0;
  int head_r=1, head_c=1;
  int next_r, next_c;
  const int mod = 4;
  queue<pair<int,int>> que;
  
  que.push(make_pair(head_r, head_c));
  while(1){

    if(idx < turn_num && time == turn[idx].first){
      if(turn[idx].second == 'L'){
        direction = (direction +mod -1) % mod;
      }else{
        direction = (direction +1) % mod;
      }
      ++idx;
    }

    ++time;
    next_r = head_r + move_next[direction][0];
    next_c = head_c + move_next[direction][1];

    if( next_r<1 || board_size < next_r || next_c<1 ||  board_size <next_c)
      return time;

    if(is_snake[next_r][next_c])
      return time;

    is_snake[next_r][next_c] = true;
    que.push(make_pair(next_r,next_c));

    if(!is_apple[next_r][next_c]){
      is_snake[que.front().first][que.front().second] = false;
      que.pop();
    }else{
      is_apple[next_r][next_c] = false;
    }
    
    head_r = next_r;
    head_c = next_c;
  }
}

int main(){
  ios_base::sync_with_stdio(0);
  cin>>board_size>>apple_num;

  memset(is_apple, false, sizeof(is_apple));
  memset(is_snake, false, sizeof(is_snake));
  is_snake[1][1] = true;

  int r,c;
  for(int i=0; i<apple_num ; ++i){
    cin>>r>>c;
    is_apple[r][c] = true;
  }

  cin>>turn_num;
  int time;
  char dir;
  for(int i=0; i<turn_num ; ++i){
    cin>>time>>dir;
    turn[i] = make_pair(time, dir);
  }

  cout<<PlayGame()<<'\n';

  return 0;
}
