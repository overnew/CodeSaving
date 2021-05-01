#include<iostream>
#include<queue>
#include<vector>
#include<string.h>
using namespace std;
typedef long long ll;

const ll MAXCOST = INT64_MAX;
int city_num, road_num;
vector<vector<pair<int,int>>> adj;
int oil_cost[2501];

struct OilStation{
  ll cost;
  int idx;
  int min_oil;

  bool operator<(const OilStation& x) const{
    return cost > x.cost;
  }

};

ll Dijkstra(int start){
  priority_queue<OilStation> pq;
  ll dist[2501][2501];
  memset(dist, 0x7f, sizeof(dist));

  pq.push({0, start, oil_cost[start]});
  dist[start][oil_cost[start]] = 0;

  int now_city, next_city, min_oil;
  ll cost, next_cost;
  while(!pq.empty()){
    now_city = pq.top().idx;
    cost = pq.top().cost;
    min_oil = pq.top().min_oil;
    pq.pop();

    if(dist[now_city][min_oil] < cost)
      continue;

    for(int i=0; i<adj[now_city].size() ; ++i){
      next_city = adj[now_city][i].second;
      next_cost = cost + (ll)adj[now_city][i].first * min_oil ; 
      //지금까지 지나온 도시 중 기름 가격이 가장 싼곳에서 미리 넣어온다고 생각(항상 이득이기 때문에)

      int next_oil = min(min_oil , oil_cost[next_city]);
      //다음 도시의 가격이 더 작다면 업데이트
      if( next_cost < dist[next_city][next_oil]){
        pq.push({next_cost, next_city, next_oil});
        dist[next_city][next_oil] = next_cost;
      }
    }
  }
    
  ll answer = MAXCOST;
  for(int i=1; i<=2500 ; ++i)
    answer = min(answer, dist[city_num][i]);
  
  return answer;
} 

int main(){
  ios_base::sync_with_stdio(0);
  cin>>city_num>>road_num;
  adj = vector<vector<pair<int,int>>>(city_num+1);

  for(int i=1; i<=city_num ; ++i)
    cin>>oil_cost[i];    

  int u, v, cost;
  for(int i=0; i<road_num ; ++i){
    cin>>u>>v>>cost;
    adj[u].push_back(make_pair(cost, v));
    adj[v].push_back(make_pair(cost, u));
  }  

  cout<<Dijkstra(1)<<'\n';

  return 0;
}
