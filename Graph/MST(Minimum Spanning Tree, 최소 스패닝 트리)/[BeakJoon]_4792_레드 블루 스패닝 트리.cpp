//https://www.acmicpc.net/problem/4792
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int vertex_num, edge_num, blue_num;

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

struct EdgeInfo{
  int u, v, cost;
  
  bool operator<(const EdgeInfo& x){
    return cost < x.cost;
  }
};

int Kruskal(vector<EdgeInfo>& edges){
  sort(edges.begin(), edges.end());

  DisjointSet sets(vertex_num+1);
  int u, v, cost;
  int used_edge_num =0, union_cnt = 0;
  for(int i=0; i<edge_num ; ++i){
    u = edges[i].u; v = edges[i].v;
    cost = edges[i].cost;

    if(sets.Find(u) == sets.Find(v))
      continue;

    sets.Union(u, v);
    ++union_cnt;
    used_edge_num += cost;

    if(union_cnt == vertex_num -1)
      break;
  }

  return used_edge_num;
}

int main(){
  ios_base::sync_with_stdio(0);
  while(1){
    cin>>vertex_num>>edge_num>>blue_num;

    if(vertex_num == 0)
      break;

    //파란 간선이 cost가 0, 빨간 간선이 cost가 1이게 저장
    vector<EdgeInfo> min_blue_edges(edge_num);  

    //파란 간선이 cost가 1, 빨간 간선이 cost가 0이게 저장
    vector<EdgeInfo> max_blue_edges(edge_num);

    char color;
    int u, v;
    for(int i=0; i<edge_num ; ++i){
      cin>>color>>u>>v;
      if(color == 'B'){
        min_blue_edges[i] = {u, v, 1};
        max_blue_edges[i] = {u, v, 0};
      }else{//빨간 간선의 경우
        min_blue_edges[i] = {u, v, 0};
        max_blue_edges[i] = {u, v, 1};
      }
    }

    //min_blue_edge로 만든 최소 스패닝 트리의 cost = 스패닝 트리의 파란 간선의 수
    int min_blue = Kruskal(min_blue_edges);

    //max_blue_edge로 만든 최소 스패닝 트리의 cost = 스패닝 트리의 빨간 간선의 수
    int max_blue = (vertex_num -1) - Kruskal(max_blue_edges);

    if(min_blue<= blue_num && blue_num <= max_blue)
      cout<<1<<'\n';
    else 
      cout<<0<<'\n';
  }

  return 0;
}
