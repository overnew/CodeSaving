//https://www.acmicpc.net/problem/2570
#include<iostream>
#include<queue>
#include<string.h>
using namespace std;

int board_size, obstacle_num;
bool is_obstacle[100][100], visited[100][100];
//기본 값은 '/' 대각선
int change_pos[2][2] = {{-1, 1}, {1, -1}};
int dir_idx[2][100][100];
vector<vector<int>> adj;
vector<bool> a_visited;
vector<int> a_match, b_match;

void DirCheckDFS(int r, int c, int idx ,int order){
  visited[r][c] = true;
  //r,c는 order번째 대각선임
  dir_idx[idx][r][c] = order;

  int next_r, next_c;
  for(int i=0; i<2 ; ++i){
    next_r = r + change_pos[i][0];
    next_c = c + change_pos[i][1];

    //범위 확인
    if(next_r <0 || board_size <= next_r || next_c < 0 || board_size <= next_c )
      continue;
    
    if(visited[next_r][next_c] || is_obstacle[next_r][next_c])
      continue;
    
    DirCheckDFS(next_r, next_c, idx, order);
  }
}

bool BipartiteMatchDFS(int a){
  if(a_visited[a])
    return false;
  a_visited[a] = true;

  int b;
  for(int i=0; i<adj[a].size() ; ++i){
    b = adj[a][i];

    if(b_match[b] == -1 || BipartiteMatchDFS(b_match[b])){
      a_match[a] = b;
      b_match[b] = a;
      return true;
    }
  }
  return false;
}

int main(){
  ios_base::sync_with_stdio(0);
  cin>>board_size>>obstacle_num;
  memset(is_obstacle, false ,sizeof(is_obstacle));

  int r, c;
  for(int i=0; i<obstacle_num ; ++i){
    cin>>r>>c;
    is_obstacle[r-1][c-1] = true;
  }

  memset(visited, false ,sizeof(visited));
  memset(dir_idx, -1 ,sizeof(dir_idx));

  // DFS로 해당 위치가 몇번째 '/'방향의 대각선에 포함되는 저장
  int dir1_order =0;
  for(int r=0; r<board_size ; ++r)
    for(int c=0; c<board_size ; ++c)
      if(!visited[r][c] && !is_obstacle[r][c])
        DirCheckDFS(r, c, 0, dir1_order++);
  
  //  '\'방향의 대각선으로 변경하여 다시 진행
  change_pos[0][0] = -1; change_pos[0][1] = -1;
  change_pos[1][0] = 1; change_pos[1][1] = 1;
  memset(visited, false ,sizeof(visited));

  int dir2_order =0;
  for(int r=0; r<board_size ; ++r)
    for(int c=0; c<board_size ; ++c)
      if(!visited[r][c] && !is_obstacle[r][c])
        DirCheckDFS(r, c, 1, dir2_order++);
    
  //이분 그래프를 위해 '/'방향 대각선의 정점들에서 '\' 대각선으로 간선 연결  
  adj = vector<vector<int>>(dir1_order);
  int dir1, dir2;
  for(int r=0; r<board_size ; ++r)
    for(int c=0; c<board_size ; ++c)
      if(!is_obstacle[r][c]){
        dir1 = dir_idx[0][r][c];
        dir2 = dir_idx[1][r][c];
        adj[dir1].push_back(dir2);
      }

  //최대 이분 매칭 진행
  a_match = vector<int>(dir1_order, -1);
  b_match = vector<int>(dir2_order, -1);

  int matching_size = 0;
  for(int start=0; start<dir1_order; ++start){
    a_visited = vector<bool>(dir1_order, false);
    
    if(BipartiteMatchDFS(start))
      matching_size++;
  }

  cout<<matching_size<<'\n';
  return 0;
}
