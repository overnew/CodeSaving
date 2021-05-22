//https://www.acmicpc.net/problem/2887
#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;

int planet_num;
vector<pair<int, int>> x_info;
vector<pair<int, int>> y_info;
vector<pair<int, int>> z_info;

class DisjointSet{  // Union find 구현
  public:
  vector<int> parent, rank;

  DisjointSet(int n): parent(n), rank(n){
    for(int i=0; i<parent.size() ; ++i) //초기는 자신이 루트
      parent[i] = i;
  }

  int Find(int u){
    if(parent[u] == u)
      return u;
    return parent[u] = Find(parent[u]);
  }

  void Union(int u, int v){
    u = Find(u); v = Find(v);
    if(u == v)
      return;

    if(rank[v] < rank[u]) //rank는 항상 v가 크게 유지
      swap(u,v);  

    parent[u] = v;  //u를 v의 하위로 Union
    if(rank[u] == rank[v])
      rank[v]++;

    return;
  }
};

struct Edge{
  int u, v, weight;

  bool operator<(const Edge& x){
    return weight < x.weight;
  }
};

void ConnectEdges(vector<Edge>& edges, const vector<pair<int, int>>& pos_info){
  int u, v, pos, next_pos, weight;
  for(int i = 0; i<planet_num-1 ; ++i){
    u = pos_info[i].second;
    v = pos_info[i+1].second;

    weight = abs(pos_info[i].first - pos_info[i+1].first);
    edges.push_back({u, v, weight});
  }
}

int main(){
  ios_base::sync_with_stdio(0);
  cin>>planet_num;

  x_info = vector<pair<int, int>>(planet_num);
  y_info = vector<pair<int, int>>(planet_num);
  z_info = vector<pair<int, int>>(planet_num);

  int x,y,z;
  for(int i = 0; i<planet_num ; ++i){
    cin>>x>>y>>z;
    x_info[i] = {x, i};
    y_info[i] = {y, i};
    z_info[i] = {z, i};
  }

  sort(x_info.begin(), x_info.end());
  sort(y_info.begin(), y_info.end());
  sort(z_info.begin(), z_info.end());

  vector<Edge> edges;
  ConnectEdges(edges, x_info);
  ConnectEdges(edges, y_info);
  ConnectEdges(edges, z_info);
  
  //그래프 생성 완료 후 크루스칼 MST 진행
  sort(edges.begin(), edges.end());

  DisjointSet sets(planet_num);

  int min_spanning = 0;
  int u, v, weight;
  for(int i=0; i<edges.size() ; ++i){
    u = edges[i].u; 
    v = edges[i].v;
    weight = edges[i].weight;

    if(sets.Find(u) == sets.Find(v))
      continue;
    
    sets.Union(u, v);
    min_spanning += weight;
  }

  cout<<min_spanning<<'\n';

  return 0;
}
