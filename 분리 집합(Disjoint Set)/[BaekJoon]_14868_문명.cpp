//https://www.acmicpc.net/problem/14868
#include<vector>
#include<cstdio>
#include<string.h>
#include<queue>
using namespace std;

class DisjointSet{
  public:
  vector<int> parent, rank;
  DisjointSet(int n) : parent(n+1) , rank(n+1) { 
    for(int i=0; i<parent.size() ; ++i)
      parent[i] = i;
  }

  int Find(int u){
    if(parent[u] == u)
      return u;
    return parent[u] = Find(parent[u]);
  }

  void Union(int u, int v){
    u = Find(u); v = Find(v);

    if(u==v)
      return;
    
    if(rank[v]< rank[u])
      swap(u,v);
    
    parent[u] = v;
    if(rank[u] == rank[v])
      rank[v]++;

    return;
  }
};

int world_size, cradle_num;
int world_map[2001][2001];
int change_pos[4][2] = { {1,0}, {-1,0}, {0, 1}, {0, -1}};
queue<pair<int,int>> bfs_q;
vector<pair<int,int>> cradles;
int edge_num =0, min_cnt=0;

bool CheckBound(int x, int y){
  if(x <=0 || x >world_size || y <=0 || y >world_size)
    return false;
  return true;
}

void CivilUnion(DisjointSet& set){
  int x, y, next_x, next_y, civil_idx;

  for(int i=0; i<cradles.size() ; ++i){ //시작부터 인접한 문명은 결합해주고 시작
    x = cradles[i].first;
    y = cradles[i].second;
    civil_idx = world_map[x][y];
    
    for(int j=0; j<4 ; ++j){  //상하좌우를 탐색
      next_x = x + change_pos[j][0];
      next_y = y + change_pos[j][1];

      if( !CheckBound(next_x,next_y)|| world_map[next_x][next_y] == 0)
        continue;
      
      if(set.Find(civil_idx) != set.Find(world_map[next_x][next_y])){//같은 집합이 아닌 경우
          set.Union(civil_idx, world_map[next_x][next_y]);
          ++edge_num;

        }
      
    }
  }

}

int CilvilPropagateBFS(){

}

int main(){
  scanf("%d %d",&world_size, &cradle_num);
  memset(world_map, 0, sizeof(world_map));

  int x, y;
  for(int i=1; i<=cradle_num ; ++i){
    scanf("%d %d", &x, &y);
    world_map[x][y] = i;  //문명의 번호
    bfs_q.push(make_pair(x, y));
    cradles.push_back(make_pair(x, y));
  }
  bool is_end = false;
  int next_x, next_y, civil_idx, min_cnt=1;
  int xx,yy;

  DisjointSet set(cradle_num);

  for(int i=0; i<cradles.size() ; ++i){ //시작부터 인접한 문명은 결합해주고 시작
    x = cradles[i].first;
    y = cradles[i].second;
    civil_idx = world_map[x][y];

    for(int j=0; j<4 ; ++j){
      next_x = x + change_pos[j][0];
      next_y = y + change_pos[j][1];

      if( !CheckBound(next_x,next_y)|| world_map[next_x][next_y] == 0)
        continue;
      
      if(set.Find(civil_idx) != set.Find(world_map[next_x][next_y])){//같은 집합이 아닌 경우
          set.Union(civil_idx, world_map[next_x][next_y]);
          ++edge_num;

          if(edge_num == cradle_num -1){
            printf("0\n");
            return 0;
          }
        }
      
    }
  }

  CivilUnion(set);
  if(edge_num == cradle_num -1){
    printf("0\n");
    return 0;
  }

  bfs_q.push(make_pair(-1, -1));
  
  

  while(!bfs_q.empty()){
    x = bfs_q.front().first;
    y = bfs_q.front().second;
    bfs_q.pop();

    if(x==-1){
      min_cnt++;
      if(bfs_q.empty())
        break;
      bfs_q.push(make_pair(-1, -1));
      continue;
    }
    civil_idx = world_map[x][y];

    for(int i=0; i<4 ; ++i){
      next_x = x + change_pos[i][0];
      next_y = y + change_pos[i][1];

      if( !CheckBound(next_x,next_y) || world_map[next_x][next_y] == civil_idx)
        continue;

      if(world_map[next_x][next_y] == 0){
        world_map[next_x][next_y] = civil_idx;
        bfs_q.push(make_pair(next_x, next_y));

        for(int j=0; j<4 ; ++j){
          xx = next_x + change_pos[j][0];
          yy = next_y + change_pos[j][1];

          if( !CheckBound(xx,yy) || world_map[xx][yy] == civil_idx||  world_map[xx][yy] == 0)
        continue;
          
          if(set.Find(civil_idx) != set.Find(world_map[xx][yy])){
            set.Union(civil_idx, world_map[xx][yy]);
          ++edge_num;

          if(edge_num == cradle_num -1){
            is_end = true;
            break;
          }
          }
        }
        
      }else{
        if(set.Find(civil_idx) != set.Find(world_map[next_x][next_y])){//같은 집합이 아닌 경우
          set.Union(civil_idx, world_map[next_x][next_y]);
          ++edge_num;

          if(edge_num == cradle_num -1){
            is_end = true;
            break;
          }
        }
        
      }
      if(is_end)
      break;
      
      
    }
    if(is_end)
      break;

  }

  printf("%d\n",min_cnt);
  return 0;
}
