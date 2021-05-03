//https://www.acmicpc.net/problem/1854
#include<iostream>
#include<queue>
#include<vector>
#include<string.h>
using namespace std;

typedef long long ll;
int city_num, road_num, K;
vector<vector<pair<ll,int>>> adj;

vector<ll> Dijkstra(int start_city){
  priority_queue<pair<ll,int>, vector<pair<ll,int>> ,greater<pair<ll,int>> > pq;
  vector<priority_queue<ll>> dist(city_num+1);
  int cnt =0;

  pq.push({0, start_city});
  dist[start_city].push(0);

  int next_city, now_city;
  ll next_cost, cost; 
  while(!pq.empty()){
    now_city = pq.top().second;
    cost = pq.top().first;
    pq.pop();

    for(int i=0; i<adj[now_city].size() ; ++i){
      next_city = adj[now_city][i].second;
      next_cost = cost + adj[now_city][i].first;

      if(dist[next_city].size() <K){
        dist[next_city].push(next_cost);
        pq.push({next_cost, next_city});
      }else if(dist[next_city].top() > next_cost){
        dist[next_city].pop();
        dist[next_city].push(next_cost);
        pq.push({next_cost, next_city});
      }
      
    }

  }

  vector<ll> ret(city_num+1,-1);
  for(int i=1; i<= city_num ; ++i)
    if(dist[i].size() == K)
      ret[i] = dist[i].top();
  
  return ret;
}

int main(){
  ios_base::sync_with_stdio(0);
  cin>>city_num>>road_num>>K;
  adj = vector<vector<pair<ll,int>>>(city_num+1);

  int u,v;
  ll cost;
  for(int i=0; i<road_num ; ++i){
    cin>>u>>v>>cost;
    adj[u].push_back({cost,v});
  }

  vector<ll> result = Dijkstra(1);
  
  for(int i=1; i<= city_num ; ++i)
    cout<<result[i]<<'\n';

  return 0;
}
