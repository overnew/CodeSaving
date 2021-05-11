//https://www.acmicpc.net/problem/11657
#include<iostream>
#include<vector>
using namespace std;

typedef long long ll;
const ll INF = 987654321;
int city_num, bus_num;
vector<vector<pair<int,ll>>> adj;

vector<ll> BellmanFord(int start_city){
  vector<ll> upper(city_num+1, INF);
  upper[start_city] = 0;
  bool is_updated = false;

  int next_city;
  ll cost;
  for(int iter = 0; iter<city_num ; ++iter){
    is_updated = false;
    for(int now_city = 1; now_city<=city_num ; ++now_city){
      if(upper[now_city] == INF)
        continue;

      for(int i = 0; i<adj[now_city].size() ; ++i){
        next_city = adj[now_city][i].first;
        cost = adj[now_city][i].second;

        if( cost + upper[now_city] < upper[next_city]){
          upper[next_city] = cost + upper[now_city];
          is_updated = true;
        }
      }
    }
    if(!is_updated) //모든 최단 경로가 구해져 완화가 안되는 경우
      break;
  }

  if(is_updated)  //음수 사이클이 존재하여 계속 완화가 가능한 경우
    upper.clear();
  return upper;
}

int main(){
  ios_base::sync_with_stdio(0);
  cin>>city_num>>bus_num;
  adj = vector<vector<pair<int,ll>>>(city_num+1);

  int u,v, cost;
  for(int i=0; i<bus_num; ++i){
    cin>>u>>v>>cost;
    adj[u].push_back({v,cost});
  }

  vector<ll> min_cost = BellmanFord(1);
  if(min_cost.size() == 0)
    cout<<-1<<'\n';
  else
    for(int i=2; i<=city_num ; ++i){
      if(min_cost[i] == INF)
        cout<<-1<<'\n';
      else
        cout<<min_cost[i]<<'\n';
    }
    
  return 0;
}
