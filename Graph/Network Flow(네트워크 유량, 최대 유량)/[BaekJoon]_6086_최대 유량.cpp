//https://www.acmicpc.net/problem/6086
#include<iostream>
#include<queue>
#include<string.h>
using namespace std;

const int INF = 987654321;
const int MAXN = 52;
int pipe_num;
int capacity[MAXN][MAXN], flow[MAXN][MAXN];

//source: 시작 지점, sink: 목적 지점
int MaximumFlow(int source, int sink){
  memset(flow, 0, sizeof(flow));
  int total_flow;

  while(1){
    vector<int> parent(MAXN, -1);
    queue<int> q;
    parent[source] = source;
    q.push(source);

    //최단으로 sink로 도달하는 경로 찾기
    while(!q.empty() && parent[sink] == -1){
      int here = q.front();
      q.pop();

      for(int there =0; there<MAXN ; ++there)
        if(capacity[here][there] - flow[here][there] > 0 && parent[there] == -1){
          q.push(there);
          parent[there] = here;
        }
    }

    //sink까지의 경로를 못 찾았다면 더이상 증가 경로가 없음
    if(parent[sink] == -1)
      break;

    // 증가 경로로 새로 흘려줄 유량 = 경로 중 최소 잔여 용량
    int amount = INF;
    for(int p = sink ; p != source  ; p = parent[p])
      amount = min(capacity[parent[p]][p] - flow[parent[p]][p], amount);
    
    //증가 경로는 유량 증가, 역 방향 경로는 유량 감소
    for(int p = sink ; p != source  ; p = parent[p]){
      flow[parent[p]][p] += amount;
      flow[p][parent[p]] -= amount;
    }

    total_flow += amount;
  }

  return total_flow;
}

int main(){
  ios_base::sync_with_stdio(0);
  cin>>pipe_num;

  memset(capacity, 0 , sizeof(capacity));
  char u, v;
  int pipe_cap;
  for(int i=0; i<pipe_num ; ++i){
    cin>>u>>v>>pipe_cap;

    if(u>90)
      u = u - 'a' + 26;
    else 
      u = u - 'A';
    
    if(v>90)
      v = v - 'a' + 26;
    else 
      v = v - 'A';

    //양방향 생성
    capacity[u][v] += pipe_cap;
    capacity[v][u] += pipe_cap;
  }

  cout<<MaximumFlow('A' - 'A','Z' - 'A' )<<"\n";
  return 0;
}
