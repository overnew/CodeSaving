//https://www.acmicpc.net/problem/2468

/*
  마침 한창 장마 계절에 풀었다. 잠기는 높이 이하의 값들은 미리 visited를 true로해 방문하지 않도록 해서 해결.
  이상하게 최댓값은 최소 0이 아닌 1이 여야해서 틀렸다. 왜 그런건지는 문제에도 나와있지 않아 잘 모르겠다. 
  + 알았다!! 비가 안왔을때는 물 높이가 0이기 때문에 아무것도 안잠기는 1을 기본값이라고 생각해야한다!
*/

#include <iostream>
#include <string.h>
using namespace std;

int n;
int max_rain=0;
int arr[100][100];
bool visited[100][100];
int ch_x[4] = {1,0,-1,0};
int ch_y[4] = {0,1,0,-1};

void Dfs(int x,int y){
  int nx,ny;
  visited[x][y] = true;

  for(int i=0; i<4 ; ++i){
    nx = x + ch_x[i];
    ny = y + ch_y[i];

    if(0<=nx && nx<n && 0<=ny && ny<n)
      if(!visited[nx][ny] )
        Dfs(nx,ny);
  }
}

int Routine(){
  int cnt=0;
  int max_area=1;
  for(int i=1; i<=max_rain ; ++i){
    memset(visited, false, sizeof(visited));
    cnt=0;

    for(int j=0; j<n ; ++j){
      for(int k=0; k<n ; ++k){
        if(arr[j][k]<=i)
          visited[j][k] = true;
      }
    }

    for(int j=0; j<n ; ++j){
      for(int k=0; k<n ; ++k){
        if(!visited[j][k]){
          Dfs(j, k);
          ++cnt;
        }
      }
    }
    max_area = max_area > cnt ? max_area : cnt;
  }
  return max_area;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin>>n;

  for(int i=0; i<n ; ++i){
    for(int j=0; j<n ; ++j){
      cin>>arr[i][j];
      max_rain = max_rain > arr[i][j] ? max_rain : arr[i][j];
    }
  }

  cout<<Routine()<<'\n';

  return 0;
}
