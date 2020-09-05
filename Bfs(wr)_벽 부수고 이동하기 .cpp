//https://www.acmicpc.net/problem/2206

#include <iostream>
#include<queue>
#include<string>
#include<string.h>
using namespace std;

int N,M;
int map[1001][1001];
int short_cut[1001][1001][2]; //벽을 뚤은 경우와 안 뚤은 경우 두가지를 서로 다르게 저장
int ch_r[4] = {1,0,-1,0};
int ch_c[4] = {0,1,0,-1};

int BreakThroughBFS(){
  queue< pair< int ,pair<int,int> > > q; //int=> 벽을 뚫기가 가능한가의 여부, 1이면 가능, 0이면 불가
  short_cut[1][1][1]= 1; //시작점도 포함하니 1부터 시작
  q.push(make_pair(1, make_pair(1, 1)));

  int nr,nc,r,c;
  bool break_pos;

  while(!q.empty()){
    break_pos = q.front().first;
    r = q.front().second.first;
    c = q.front().second.second;
    q.pop();

    if(r == N && c== M)
      return short_cut[r][c][break_pos];// break_pos가 뭐든 먼저 도달한 것이 답.

    for(int i=0; i<4 ; ++i){
      nr = r + ch_r[i];
      nc = c + ch_c[i]; 

      if( 1<= nr && nr <=N && 1<= nc && nc <=M ){//범위 검사
        if(map[nr][nc]==1 && break_pos==1){ //벽이고 벽뚫기가 가능한 경우
          q.push(make_pair(0, make_pair(nr, nc)));
          short_cut[nr][nc][0] = short_cut[r][c][break_pos] +1;

        }else if(map[nr][nc] ==0 && short_cut[nr][nc][break_pos] == 0){ 
          q.push(make_pair(break_pos, make_pair(nr, nc)));
          short_cut[nr][nc][break_pos] = short_cut[r][c][break_pos] +1;

        }

        
      }
    }//fro문 끝

  }//while끝

  return -1;
}

int main() {
  string temp;
  cin>>N>>M;

  for(int i=1; i<=N ; ++i){
    cin>>temp;
    for(int j=1; j<=M ; ++j)
      map[i][j] = temp[j-1] - '0';
    
  }

  memset(short_cut, 0, sizeof(short_cut));

  cout<<BreakThroughBFS()<<'\n';

  return 0;
}
