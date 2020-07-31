//https://www.acmicpc.net/problem/1260

//DFS는 재귀, BFS는 큐로 구현

#include <iostream>
#include<string.h>
#include<stack>
#include<queue>
using namespace std;

int n,m,start_point;
bool graph[1001][1001];
bool visited[1001];

void Dfs(int v){
  visited[v] = true;
  cout<<v<<' ';
  for(int i=1; i<=n ; ++i){
    if(graph[v][i] && !visited[i])
      Dfs(i);
  }
}

void Bfs_search(int v){
  int node;
  queue<int> q;
  q.push(v);
  visited[v] = true;
  cout<<v<<' ';

  while(!q.empty()){
    node = q.front();
    q.pop();

    for(int i=1; i<=n ; ++i){
      if(graph[node][i] && !visited[i]){
        visited[i] = true;
        q.push(i);
        cout<<i<<' ';
      }
    }
  }

}

int main() {
  int fr, se;

  ios_base::sync_with_stdio(0);
  cin>>n>>m>>start_point;

  memset(graph, false, sizeof(graph));
  memset(visited, false, sizeof(visited));

  for(int i=0; i<m ; ++i){
    cin>>fr>>se;
    graph[fr][se] = true;
    graph[se][fr] = true;
  }

  Dfs(start_point);
  cout<<'\n';

  memset(visited, false, sizeof(visited));
  Bfs_search(start_point);
  cout<<'\n';

  return 0;
}
