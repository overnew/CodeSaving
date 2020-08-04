//https://www.acmicpc.net/problem/11724

/*
  간단한 Dfs. 
  무방향임으로 서로를 true로 연결하고, visited를 이용해 dfs 서칭을 하면, 트리(dfs 스패닝 트리)의 개수가 나온다 -> 연결 요소의 개수
*/

#include <iostream>
#include<vector>
using namespace std;

int n,m;
vector<vector<bool>> graph;
vector<bool> visited;

void Dfs(int ver){
  visited[ver] = true;

  for(int i=1; i<=n ; ++i){
    if(graph[ver][i]&& !visited[i])
      Dfs(i);
  }

}

int main() {
  int u,v;
  int cnt=0;
  ios_base::sync_with_stdio(0);
  cin>>n>>m;

  graph = vector<vector<bool>>(n+1,vector<bool>(n+1, false));
  visited = vector<bool>(n+1,false);

  for(int i=0; i<m ; ++i){
    cin>>u>>v;
    graph[u][v]= true;
    graph[v][u]=true;
  }

  for(int i=1; i<=n ; ++i){
    if(!visited[i]){
      Dfs(i);
      ++cnt;
    }
  }

  cout<<cnt<<'\n';
  
  return 0;
}
