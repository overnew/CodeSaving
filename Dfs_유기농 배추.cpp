//https://www.acmicpc.net/problem/1012

/*
  단지 번호 붙이기와 매우 유사. 실제로도 비슷하게 풀었다.
  bool arr[50][50];
  bool visited[50][50]; 를 통해 방문을 하지 않았고 배추가 심어진 곳이면 방문해서 dfs 탐색을 
*/

#include <iostream>
#include <string.h>
using namespace std;

int t,m,n,k;
bool arr[50][50];
bool visited[50][50];
int ch_x[4] = {1,0,-1,0};
int ch_y[4] = {0,1,0,-1};

void whiteWarm(int x,int y){
  int nx,ny;
  visited[x][y] = true;

  for(int i=0; i<4 ; ++i){
    nx = x+ ch_x[i];
    ny = y + ch_y[i];

    if(0 <= nx && nx<m && 0<=ny && ny<n){
      if(arr[nx][ny] && !visited[nx][ny]) //방문하지 않았을 경우에만
        whiteWarm(nx,ny);
    }
  }


}

int main() {
  int a,b;
  ios_base::sync_with_stdio(0);
  cin>>t;

  for(int i=0; i<t ; ++i){
    int cnt =0;
    cin>>m>>n>>k;

    memset(arr, false,sizeof(arr));
    memset(visited, false,sizeof(visited));

    for(int j=0; j<k ; ++j){
      cin>>a>>b;
     arr[a][b] = true;
    }

    for(int fr =0; fr<m ; ++fr){
      for(int se=0; se<n ; ++se){

        if(arr[fr][se] && !visited[fr][se]){
          whiteWarm(fr, se);
          ++cnt;
        }
      }
    }
    cout<<cnt<<'\n';
  }
  

  return 0;
}
