//https://www.acmicpc.net/problem/14502

#include <iostream>
#include<string.h>
using namespace std;

int n,m;
int max0 =0;
int cnt=0;
int arr[8][8];
int arr_copy[8][8];
int visited[8][8];
int ch_x[4] = {1,0,-1,0};
int ch_y[4] = {0,1,0,-1};

void Corona(int x,int y){
  int nx,ny;
  visited[x][y] = true;

  for(int i=0; i<4 ; ++i){
    nx = x+ch_x[i];
    ny = y+ch_y[i];
    
    if(0<=nx && nx < m && 0<=ny && ny <n){
      if(!visited[nx][ny] && arr_copy[nx][ny] == 2){//1만 아니면 가주아~
        arr_copy[nx][ny] = 2;
        Corona(nx,ny);
      }
    }
  }

}

void Routine(){
  int count=0;
  memset(visited, false, sizeof(visited));

  for(int i=0; i<n ; ++i){
    for(int j=0; j<m ; ++j){
      arr_copy[i][j] = arr[i][j];
    }
  }

  for(int i=0; i<n ; ++i){
    for(int j=0; j<m ; ++j){
      if(!visited[i][j] && arr_copy[i][j] ==2)
        Corona(i, j);
    }
  }

  for(int i=0; i<n ; ++i){
    for(int j=0; j<m ; ++j){
      if(arr_copy[i][j] ==0)
        ++count;
    }
  }
  //cout<<count<<endl;

  max0 = max0 > count ? max0: count;
}

void makeWall(int c){
  if(c==3){
    Routine();
    return;
  }
  for(int i=0; i<n ; ++i){
    for(int j=0; j<m ; ++j){
      if(arr[i][j] ==0){
        arr[i][j]=1;
        makeWall(c+1);
        arr[i][j] =0;
      }
    }
  }
}

void FillWall(int x,int y){
  int nx=x;
  int ny=y;

  if(cnt ==2){
    arr[x][y] = 1;
    Routine();
    --cnt;
    arr[x][y] = 0;
    return;
  }else{


    arr[x][y] = 1;
    while(1){
      if(x+1 >= m){
        ++ny;
        nx =0;
      }
      else
        ++nx;
      if(ny == n)
        break;

      if(arr_copy[nx][ny] == 0){
        ++cnt;
        FillWall(nx, ny);
      }
    }
    arr[x][y] = 0;
    cnt--;
  }
}

int main() {
  cin>>n>>m;

  for(int i=0; i<n ; ++i){
    for(int j=0; j<m ; ++j){
      cin>>arr[i][j];
      arr_copy[i][j] = arr[i][j];
    }
  }

  
  makeWall(1);

  cout<<max0<<'\n';
  return 0;
}
