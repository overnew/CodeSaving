//https://www.acmicpc.net/problem/12851
#include<iostream>
#include<queue>
#include<string.h>
using namespace std;

const int MAXN = 100000;
int time_cache[MAXN + 1];
int case_cache[MAXN + 1];

pair<int,int> BFS(int start_pos, int dest_pos){
  queue<int> que;
  que.push(start_pos);
  time_cache[start_pos] = 0;
  case_cache[start_pos] = 1;

  int pos,next_pos, time,case_num;
  while(!que.empty()){
    pos = que.front();
    que.pop();
    time = time_cache[pos];
    case_num = case_cache[pos];

    if(pos == dest_pos)
      break;

    for(int i=0; i<3 ; ++i){
      switch(i){
        case 0:
          next_pos = pos -1;
        break;
        case 1:
          next_pos = pos +1;
        break;
        case 2:
          next_pos = pos*2;
      }

      if(next_pos < 0 || MAXN < next_pos )  //범위 초과 판단
        continue;
      
      if(time_cache[next_pos] == -1){//방문한적 없는 경우
        que.push(next_pos);
        time_cache[next_pos] = time +1;
        case_cache[next_pos] = case_num;
      }else if(time_cache[next_pos] == time +1){  //최단 시간에 도달하는 경로가 여러가지인 경우
        case_cache[next_pos] += case_num;
      }

    }// for문 end;

  }

  return make_pair(time_cache[dest_pos], case_cache[dest_pos]);
}

int main(){
  ios_base::sync_with_stdio(0);
  int start_pos, dest_pos;
  cin>>start_pos>>dest_pos;

  memset(time_cache, -1 , sizeof(time_cache));
  memset(case_cache, -1 , sizeof(case_cache));

  pair<int,int> result = BFS(start_pos,dest_pos );
  cout<<time_cache[dest_pos]<<"\n"<<case_cache[dest_pos]<<"\n";

  return 0;
}
