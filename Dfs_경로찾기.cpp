//https://www.acmicpc.net/problem/11403

/*
  Dfs,Bfs로도 
*/

#include <iostream>
#include <string.h>
using namespace std;

int n;
int graph[100][100];
int pos_travel[100][100];
bool visited[100];

void Dfs(int v, int now){
  if(v!= now){    //v,now가 같다면 처음 호출한 시점이기 때문에 그래프를 통해 now가 접근되지 않는이상 now의 pos를 1로 해주면 안됨
    visited[v] = true;
    pos_travel[now][v] =1;  //now에서 가능한 것들 넣어줌
  }

  for(int i=0; i<n ; ++i){
    if(graph[v][i] && !visited[i]){
      if(i==now){
        visited[now] = true;
        pos_travel[now][now] =1;
      }else
        Dfs(i,now);
    }
  }
}

void Routine(){
  
  for(int i=0; i<n ; ++i){
    memset(visited, false, sizeof(visited));
    Dfs(i, i);  
  }
}

int main() {
  cin>>n;

  for(int i=0; i<n ; ++i){
    for(int j=0; j<n ; ++j){
      cin>>graph[i][j];
    }
  }
  memset(pos_travel,0,sizeof(pos_travel));
 
  Routine();

  for(int i=0; i<n ; ++i){
    for(int j=0; j<n ; ++j){
      cout<<pos_travel[i][j]<<' ';
    }
    cout<<'\n';
  }
  return 0;
}
