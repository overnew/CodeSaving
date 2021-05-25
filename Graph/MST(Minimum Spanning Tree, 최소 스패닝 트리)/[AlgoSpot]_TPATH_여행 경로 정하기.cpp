//https://algospot.com/judge/problem/read/TPATH
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int station_num, line_num;

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

struct LineInfo{
  int u, v, speed;
  
  bool operator<(const LineInfo& x){
    return speed < x.speed;
  }
};

int KruskalMinUpper(vector<LineInfo>& edges , const int lower_idx){

  DisjointSet sets(station_num);

  int u, v, union_cnt =0;
  for(int i=lower_idx; i<edges.size() ; ++i){
    u = edges[i].u; v = edges[i].v;

    if(sets.Find(u) == sets.Find(v))
      continue;
    
    sets.Union(u, v);
    union_cnt++;

    if(sets.Find(0) == sets.Find(station_num-1))
      return edges[i].speed;

    if(union_cnt == station_num-1)
      break;
  }
  return 1001;
}


int main(){
  ios_base::sync_with_stdio(0);
  int test_num;
  cin>>test_num;

  while(test_num--){
    cin>>station_num>>line_num;
    vector<LineInfo> edges(line_num);

    int u, v, speed, max_speed = 0;
    for(int i=0; i<line_num ; ++i){
      cin>>u>>v>>speed;
      edges[i] = {u,v,speed};
      max_speed = max(speed, max_speed);
    }

    sort(edges.begin(), edges.end());

    int lower = -1,upper , min_gap = 1001;
    for(int i=0; i<edges.size() ; ++i){
      if( lower >= edges[i].speed )
        continue;
      
      lower= edges[i].speed;
      upper = KruskalMinUpper(edges, i);
      if(upper == 1001) //더 이상 연결이 불가능
        break;

      min_gap = min(upper - lower, min_gap);
    }

    cout<<min_gap<<"\n";

  }

  return 0;
}
