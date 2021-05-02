//https://algospot.com/judge/problem/read/FIRETRUCKS
#include<iostream>
#include<queue>
#include<vector>
#include<string.h>
using namespace std;

int place_num,road_num, burning_num, station_num;
vector<vector<pair<int,int>>> adj;
int station[1001], burning_place[1001];
bool is_station[1001];
int dist[1001];

void Dijkstra(int start_station){
  priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
  pq.push({0,start_station});
  dist[start_station] = 0;
  
  int now_place, cost, next_place, next_cost;
  while(!pq.empty()){
    now_place = pq.top().second;
    cost = pq.top().first;
    pq.pop();

    if(dist[now_place] < cost) 
      continue;

    for(int i=0; i<adj[now_place].size() ; ++i){
      next_place = adj[now_place][i].second;

      if(is_station[next_place])  //다음 장소가 소방소라면 더 이상 탐색 x 
        continue;

      next_cost = cost + adj[now_place][i].first;

      if(next_cost < dist[next_place]){
        pq.push({next_cost, next_place});
        dist[next_place] = next_cost;
      }
    }
  }

}

int main(){
  ios_base::sync_with_stdio(0);
  int test_num;
  cin>>test_num;

  while(test_num--){
    cin>>place_num>>road_num>>burning_num>>station_num;
    memset(is_station, false, sizeof(is_station));
    memset(dist, 0x7f , sizeof(dist));
    adj = vector<vector<pair<int,int>>>(place_num+1);

    int u, v, cost;
    for(int i=0; i<road_num ; ++i){
      cin>>u>>v>>cost;
      adj[u].push_back({cost, v});
      adj[v].push_back({cost, u});
    }

    for(int i=0; i<burning_num ; ++i)
      cin>>burning_place[i];

    for(int i=0; i<station_num ; ++i){
      cin>>station[i];
      is_station[station[i]] = true;
    }
    
    for(int i=0; i<station_num ; ++i)
      Dijkstra(station[i]);

    long long total_cost = 0;
    for(int i=0; i<burning_num ; ++i)
      total_cost += dist[burning_place[i]];

    cout<<total_cost<<'\n';
  }

  return 0;
}
