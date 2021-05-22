//https://www.acmicpc.net/problem/1944
#include<iostream>
#include<string>
#include<string.h>
#include<queue>
#include<algorithm>
using namespace std;

int maze_size, key_num;
char maze_map[50][50];
int change_pos[4][2] = {{1,0}, {-1, 0}, {0,1}, {0,-1}};
int dist[251][251];
pair<int,int> convert_idx2pos[251];
int convert_pos2idx[50][50];

struct Vertex{
  int r, c, depth;
};

struct Edge{
  int u, v, weight;

  bool operator<(const Edge& x){
    return weight < x.weight;
  }
};

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

bool ConnectEdgeBFS(int start_r, int start_c){
  queue<Vertex> q;
  bool is_in_que[50][50];
  memset(is_in_que, false ,sizeof(is_in_que));

  int start_idx = convert_pos2idx[start_r][start_c];
  int cnt_vertex = 0;

  q.push({start_r, start_c,0});
  is_in_que[start_r][start_c] = true;

  int r,c, next_r, next_c, next_depth, next_idx;
  while(!q.empty()){
    r = q.front().r;
    c = q.front().c;
    next_depth = q.front().depth + 1;
    q.pop();

    for(int i=0; i<4 ; ++i){
      next_r = r + change_pos[i][0];
      next_c = c + change_pos[i][1];

      //범위 확인
      if(next_r <0 || maze_size <= next_r || next_c<0 || maze_size<= next_c)
        continue;
      //이미 큐에 삽입된 적 있다면 패스
      if(is_in_que[next_r][next_c] || maze_map[next_r][next_c] == '1')
        continue;
      
      q.push({next_r, next_c, next_depth});
      is_in_que[next_r][next_c] = true;
      
      if(maze_map[next_r][next_c] == 'K' || maze_map[next_r][next_c] == 'S'){
        next_idx = convert_pos2idx[next_r][next_c];
        dist[start_idx][next_idx] = next_depth;
        ++cnt_vertex;
      }
    }

  }

  return cnt_vertex == key_num;
}


int Kruskal(){
  int min_spanning=0;
  vector<Edge> edges;
  
  for(int u=0; u<=key_num ; ++u){
    for(int v=0; v<=key_num ; ++v){
      if(u==v)
        continue;
      edges.push_back({u,v, dist[u][v]});
    }
  }

  sort(edges.begin(), edges.end());

  DisjointSet sets(key_num+1);  //초기에는 모두 독립 집합

  int u, v, weight;
  for(int i=0; i<edges.size() ; ++i){
    u = edges[i].u; v = edges[i].v;
    weight = edges[i].weight;

    if(sets.Find(u) == sets.Find(v))  //이미 합쳐진 경우
      continue;

    sets.Union(u, v); //간선을 이었으므로 유니온
    min_spanning += weight;

  }

  return min_spanning;
}

int main(){
  ios_base::sync_with_stdio(0);
  cin>>maze_size>>key_num;

  int order =0;
  string temp;
  for(int i=0; i<maze_size ; ++i){
    cin>>temp;
    for(int j=0 ; j<maze_size ; ++j){
      maze_map[i][j] = temp[j];
      if(maze_map[i][j] == 'S' || maze_map[i][j] == 'K'){
        convert_pos2idx[i][j] = order;
        convert_idx2pos[order++] = {i, j};
      }
        
    }
  }

  int r, c;
  for(int i=0; i<=key_num ; ++i){
    r = convert_idx2pos[i].first;
    c = convert_idx2pos[i].second;

    //모든 키를 획득할 수 없는 경우
    if(!ConnectEdgeBFS(r, c)){  
      cout<<-1<<'\n';
      return 0;
    }
  }
  
  cout<<Kruskal()<<'\n';

  return 0;
}
