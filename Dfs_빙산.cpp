//https://www.acmicpc.net/problem/2573

/*
  먼저 Dfs 서칭으로 두개 이상의 덩어리로 이어져 있는 지 확인.
  아니라면
  meltDfs를 통해 이러진 빙하들을 돌면 주위의 0을 확인해 melt시킴.
  두개 이상이라면 호출 횟수를 return
  0개라면 한번에 모두 녹아버린 것으로 0을 반환
  이를 반복쓰
  
  +nr,nc를 써야하는곳에 r 과 c를 써버려서 한참을 해맸다..
*/

#include <iostream>
#include<string.h>
using namespace std;

int n,m;
int ice[300][300];
//int copy[300][300];
bool visited[300][300];
int ch_r[4] = {1,0,-1,0};
int ch_c[4] = {0,1,0,-1};

void meltDfs(int r,int c){
  int nr,nc;
  visited[r][c] = true;


  for(int i=0; i<4 ; ++i){
    nr = r+ ch_r[i];
    nc = c+ ch_c[i];

    if(0<=nr && nr<n && 0<=nc && nc<m){

      if(ice[nr][nc] != 0){
        if(!visited[nr][nc]) //ret가 0으로 변화했을때를 대비해 이미 방문되면 영향x
          meltDfs(nr, nc);
      }else{
        if(!visited[nr][nc] && ice[r][c]>0) //ret가 0으로 변화했을때를 대비해 이미 방문되면 영향x , 0이되면 그대로 놔둠 ->핵심쓰
          --ice[r][c];
      }

    }

  }
}

void Dfs(int r,int c){
  int nr,nc;
  visited[r][c] = true;

  for(int i=0; i<4 ; ++i){
    nr= r+ ch_r[i];
    nc = c+ ch_c[i];

    if(0<=nr && nr<n && 0<=nc && nc<m){
      if(!visited[nr][nc] && ice[nr][nc] != 0)
        Dfs(nr, nc);
    }
  }
}

int Routine(){
  int passed_year=0;

  while(1){
    int cnt=0;
    
    memset(visited, false, sizeof(visited));

    for(int i=0; i<n ; ++i){
      for(int j=0; j<m ; ++j){
        if(!visited[i][j] && ice[i][j] != 0){
          Dfs(i, j);
          ++cnt;
        }
      }
    }

    if(cnt==0)
      return 0;
    else if(cnt>1){
      return passed_year;
    }else{ //아직 1일때
      ++passed_year;
      memset(visited, false, sizeof(visited));

      for(int i=0; i<n ; ++i){
        for(int j=0; j<m ; ++j){
          if(!visited[i][j] && ice[i][j] != 0){
            meltDfs(i, j);
          }
        }
      }

    }


  }
}

int main() {
  cin>>n>>m;
  
  for(int i=0; i<n ; ++i){
    for(int j=0; j<m ; ++j){
      cin>>ice[i][j];
    }
  }

  int result = Routine();
  cout<<result<<'\n';


  return 0;
}
