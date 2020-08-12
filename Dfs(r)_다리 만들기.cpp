//https://www.acmicpc.net/problem/2146

#include <iostream>
#include <string.h>
using namespace std;

int n;
int is_num;
int min_len =10000;
int arr[100][100];
int island[100][100];
bool visited[100][100];
int ch_x[4] = {1,0,-1,0};
int ch_y[4] = {0,1,0,-1};

void checkIsland(int x,int y){
  int nx,ny;
  island[x][y] = is_num;

  for(int i=0; i<4 ; ++i){
    nx = x+ch_x[i];
    ny = y + ch_y[i];

    if(0<=nx && nx <n && 0<=ny && ny<n)
      if(!island[nx][ny])
        checkIsland(nx, ny);
  }
}

void BridgeDfs(int x,int y,int idx, int cnt){
  if(cnt>=min_len)//더 찾아볼 필요x
    return;

  int nx,ny;
  visited[x][y] = true;

  for(int i=0; i<4 ; ++i){
    nx = x+ch_x[i];
    ny = y + ch_y[i];

    if(0<=nx && nx <n && 0<=ny && ny<n){
      if(island[nx][ny]!= 0 && island[nx][ny] != idx)
        min_len = min_len< cnt ? min_len : cnt;
      else if(!visited[nx][ny]){
        BridgeDfs(nx, ny, idx, cnt+1);
      }

    }
  }

}

void Routine(){
  for(;;){
    for(;;){

    }
  }
}

int main() {
  cin>>n;

  for(int i=0; i<n ; ++i){
    for(int j=0; j<n ; ++j){
      cin>>arr[i][j];
    }
  }
  memset(island, false, sizeof(island));
  

  return 0;
}
