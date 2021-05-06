//https://algospot.com/judge/problem/read/NTHLON
#include<iostream>
#include<queue>
#include<vector>
#include<string.h>
#include<cmath>
using namespace std;

int event_num;
int event_timeA[501], event_timeB[501];
int time_gap[501];
const int START_IDX = 401;
const int INF = INT32_MAX;

int Vertax(int delta){
  return delta + 200;
}

int Dijkstra(vector<vector<pair<int,int>>>& adj){
  priority_queue<pair<int,int>, vector<pair<int,int>> , greater<pair<int,int>>> pq;
  vector<int> dist(402, INF);

  pq.push({0,START_IDX});
  dist[START_IDX] = 0;

  int next_idx, now_idx, cost, next_cost;
  while(!pq.empty()){
    cost = pq.top().first;
    now_idx = pq.top().second;
    pq.pop();

    if(dist[now_idx] < cost)
      continue;
  
    for(int i=0; i<adj[now_idx].size() ; ++i){
      next_cost = cost + adj[now_idx][i].first;
      next_idx = adj[now_idx][i].second;

      if(next_cost < dist[next_idx]){
        pq.push({next_cost,next_idx});
        dist[next_idx] = next_cost;
      }
    }
  }

  return dist[Vertax(0)];
}

int FindMinDraw(){
  vector<vector<pair<int,int>>> adj(402);

  int gap;
  for(int i= 0; i<event_num ; ++i){
    gap = event_timeA[i] - event_timeB[i];
    time_gap[i] = gap;
    adj[START_IDX].push_back({event_timeA[i], Vertax(gap)});
  }

  int next_idx;
  for(int vertax_idx = -200; vertax_idx<=200 ; ++vertax_idx){
    for(int event_idx = 0; event_idx<event_num ; ++event_idx){
      next_idx = vertax_idx + time_gap[event_idx];

      if(abs(next_idx)>200) 
        continue;

      adj[Vertax(vertax_idx)].push_back({ event_timeA[event_idx], Vertax(next_idx)});
    }
  }

  int ret = Dijkstra(adj);
  if(ret == INF)
    return  -1;

  return  ret;
}

int main(){
  ios_base::sync_with_stdio(0);
  int test_num;
  cin>>test_num;

  while(test_num--){
    cin>>event_num;

    for(int i=0 ; i<event_num ; ++i)
      cin>>event_timeA[i]>>event_timeB[i];

    int answer = FindMinDraw();
    if(answer == -1)
      cout<<"IMPOSSIBLE\n";
    else
      cout<<answer<<'\n';    
  }

  return 0;
}
