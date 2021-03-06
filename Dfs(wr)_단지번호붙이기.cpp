//https://www.acmicpc.net/problem/2667

/*
  bfs로도 풀수 있는 문제.
  DFS의 경우 -> 스택을 활용해 최근에 넣은 것을 pop해 4가지로 뻗어 나감.
  BFS의 경우 -> 큐를 활용: 먼저 넣은 것을 먼저 pop해서 4가지 분류를 큐의 뒤에 
*/

#include <iostream>
#include<string>
#include<string.h>
#include<algorithm>
#include<vector>
using namespace std;

int n,cnt;
//int arr[25][25];
string arr[25];
bool visited[25][25];
vector<int> ans;
int change_x[4] = {0,1,0,-1};
int change_y[4] = {-1,0,1,0};

void Dfs(int x,int y){
  visited[x][y] = true;
  cnt++;

  for(int i=0; i<4; ++i){
    int nx = x+change_x[i];
    int ny = y+change_y[i];

    if( 0<= nx && nx< n && 0<= ny && ny< n)
      if(arr[nx][ny] =='1' && visited[nx][ny]==false)
        Dfs(nx,ny);

  }
} 


int main() {
  cin>>n;

  memset(visited, false, sizeof(visited));

  for(int i=0; i<n ; ++i){
    cin>>arr[i];
  }

  for(int i=0; i<n ; ++i){
    for(int j=0; j<n ; ++j){
      if(arr[i][j] == '1' && visited[i][j]==false){
        cnt=0;
        Dfs(i, j);
        ans.push_back(cnt);
      }
        
    }
  }

  sort(ans.begin(), ans.end());

  cout<<ans.size()<<'\n';
  for(int i=0; i<ans.size()  ;++i){
    cout<<ans[i] <<'\n';
  }

  return 0;
}
