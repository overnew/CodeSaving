//https://www.acmicpc.net/problem/1162
#include<iostream>
#include<queue>
#include<vector>
#include<cstdio>
#include<string.h>
using namespace std;
typedef long long ll;
const ll MAXTIME = INT64_MAX;

struct Distance{
  ll cost;
  ll idx;
  ll paved;

  bool operator<(const Distance& a) const{
    return cost > a.cost;
  }
};

int city_num, road_num, pave_num;
vector<pair<ll,ll>> adj[10001];

ll Dijkstra(int start_node){
  ll dist[10001][21];
  memset(dist, 0x3f, sizeof(dist));

  priority_queue<Distance> pq;
  pq.push({0,start_node,0});
  dist[start_node][0] = 0;

  ll now_node, next_node, paved;
  ll cost, next_cost;

  while(!pq.empty()){
    now_node = pq.top().idx;
    cost = pq.top().cost;
    paved = pq.top().paved;
    pq.pop();

    if(dist[now_node][paved] < cost)
      continue;

    for(int i=0; i<adj[now_node].size() ; ++i){
      next_node = adj[now_node][i].second;
      next_cost = cost + adj[now_node][i].first;

      if(next_cost < dist[next_node][paved]){
        pq.push({next_cost, next_node ,paved});
        dist[next_node][paved] = next_cost;
      }

      if(paved  < pave_num && cost < dist[next_node][paved+1]){
        pq.push({cost, next_node ,paved+1});
        dist[next_node][paved+1] = cost;
      }
    }

  }

  ll min_cost = MAXTIME;
  for(int i=0; i<=pave_num ; ++i)
    min_cost = min(min_cost, dist[city_num][i]);

  return min_cost;
}

int main(){
  scanf("%d %d %d",&city_num, &road_num, &pave_num);

  ll u, v, cost;
  for(int i=0; i<road_num ; ++i){
    scanf("%lld %lld %lld",&u, &v, &cost);
    adj[u].push_back(make_pair(cost,v));
    adj[v].push_back(make_pair(cost,u));
  }

  printf("%lld\n", Dijkstra(1));

  return 0;
}
