//https://algospot.com/judge/problem/read/DRUNKEN
#include<iostream>
#include<string.h>
#include<algorithm>
using namespace std;

const int MAXCOST = 60000;
int vertex_num, edge_num;
int adj[501][501], max_expect[501][501];
pair<int,int> inspection_time[501];

void CalcMaxExpectDist(){
  //측정 시간이 짧게 걸리는 순으로 정렬
  sort(inspection_time, inspection_time+vertex_num);  

  for(int k = 0; k<vertex_num ; ++k){
    int via_idx = inspection_time[k].second;
    int delay = inspection_time[k].first;

    for(int i = 1; i<=vertex_num ; ++i){
      for(int j = 1; j<=vertex_num ; ++j){
        adj[i][j] = min(adj[i][j], adj[i][via_idx] + adj[via_idx][j]);
        max_expect[i][j] = min(max_expect
        [i][j], adj[i][via_idx] + adj[via_idx][j] + delay);
      }
    }

  }
}

int main(){
  ios_base::sync_with_stdio(0);
  cin>>vertex_num>>edge_num;

  memset(adj, 0x3f  , sizeof(adj)); //충분히 큰 수로 초기화
  memset(max_expect, 0x3f  , sizeof(max_expect));
  for(int i=1; i<=vertex_num ; i++)
    adj[i][i] = max_expect[i][i] = 0;

  int time;
  for(int i=0; i<vertex_num ; i++){
    cin>>time;
    inspection_time[i] = {time ,i+1};
  }
  
  int u, v, cost;
  for(int i=0; i<edge_num ; ++i){
    cin>>u>>v>>cost;
    adj[u][v]  = max_expect[u][v]= cost;
    adj[v][u] = max_expect[v][u]= cost;
  }

  CalcMaxExpectDist();

  int test_num, s, t;
  cin>>test_num;
  for(int i=0; i<test_num ; ++i){
    cin>>s>>t;
    cout<<max_expect[s][t]<<"\n";
  }
    
  return 0;
}
