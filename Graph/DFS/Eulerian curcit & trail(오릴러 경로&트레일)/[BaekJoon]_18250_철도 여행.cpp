//https://www.acmicpc.net/problem/18250
#include<iostream>
#include<vector>
using namespace std;

int city_num, rail_num;
vector<bool> visited;
vector<vector<int>> adj;
vector<int> degree;

int CountOddDegree(int city_idx){
  visited[city_idx] = true;
  if(degree[city_idx] == 0) //어떤 철로도 연결되지 않은 도시는 여행에 포함X
    return -1;

  int cnt =0;
  if(degree[city_idx] %2 == 1)
    ++cnt;

  for(int i=0; i<adj[city_idx].size() ; ++i)
    if(!visited[adj[city_idx][i]]) //방문을 하지 않은 경우만
      cnt += CountOddDegree(adj[city_idx][i]);
  
  return cnt;
}

int main(){
  ios_base::sync_with_stdio(0);
  cin>>city_num>>rail_num;

  visited = vector<bool>(city_num+1, false);
  adj = vector<vector<int>>(city_num+1);
  degree = vector<int>(city_num+1,0);

  int u,v;
  for(int i=0; i<rail_num ; ++i){
    cin>>u>>v;
    adj[u].push_back(v);
    adj[v].push_back(u);
    ++degree[u];
    ++degree[v];
  }

  int odd_degree_num, min_travel_num=0;  
  for(int idx=1; idx<=city_num ; ++idx){
    if(!visited[idx]){
      odd_degree_num = CountOddDegree(idx);
      if(odd_degree_num == 0)
        min_travel_num += 1;
      else if(odd_degree_num == -1)
        continue;
      else
        min_travel_num += odd_degree_num/2;
    }
  }

  cout<<min_travel_num<<'\n';

  return 0;
}
