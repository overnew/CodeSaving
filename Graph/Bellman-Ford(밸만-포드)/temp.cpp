#include<iostream>
#include<vector>
#include<string.h>
#include<queue>
using namespace std;

struct Vertex{
  int r;
  int c;
  int time;
};

const int INF = 10000000;
int height, width, grave_num, hole_num;
bool is_grave[30][30], is_hole[30][30], is_exit[30][30];
bool visited[30][30];
int change_pos[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};
vector<vector<pair<int,int>>> hole_out;
vector<vector<vector<Vertex>>> adj;

int BellmanFord(){
  vector<vector<int>> upper(height, vector<int>(width, INF));
  bool is_updated = false;
  upper[0][0] = 0;

  int time, next_r ,next_c;
  for(int iter =0; iter< (height*width)-grave_num ; ++iter){
    is_updated = false;
    for(int r =0; r<height ; ++r){
      for(int c = 0; c<width ; ++c){
        if(is_grave[r][c]) continue;

        for(int i=0; i<adj[r][c].size() ; ++i){
          next_r = adj[r][c][i].r;
          next_c = adj[r][c][i].c;
          time = adj[r][c][i].time;

          if(time + upper[r][c] < upper[next_r][next_c]){
            is_updated = true;
            upper[next_r][next_c] = time + upper[r][c];
          }
        }

      }
    }
    if(!is_updated)
      break;
  }

  if(is_updated)
    return -1;
  return upper[height-1][width-1];
}


bool MakeGraphBFS(){
  queue<pair<int,int>> q;
  bool in_que[30][30];
  memset(in_que, false ,sizeof(in_que));
  q.push({0,0});
  in_que[0][0] = true;

  int now_r, now_c,next_r ,next_c, out_r, out_c;
  while(!q.empty()){
    now_r = q.front().first;
    now_c = q.front().second;
    visited[now_r][now_c] = true;
    q.pop();

    if(is_hole[now_r][now_c]){
      out_r = hole_out[now_r][now_c].first;
      out_c = hole_out[now_r][now_c].second;
      if(!in_que[out_r][out_c])
        in_que[out_r][out_c] = true;
      q.push({out_r, out_c});
    }

    for(int i=0; i<4 ; ++i){
      next_r = now_r + change_pos[i][0];
      next_c = now_c + change_pos[i][1];
      if(next_r<0 || height<= next_r || next_c<0 || width<=next_c)
        continue;

      if(visited[next_r][next_c] || is_grave[next_r][next_c])
        continue;

      if(!in_que[next_r][next_c]){
        in_que[next_r][next_c] = true;
        q.push({next_r, next_c});
      }
      if(!is_hole[now_r][now_c])
        adj[now_r][now_c].push_back({next_r, next_c,1});
      
      adj[next_r][next_c].push_back({now_r, now_c,1});
    }
  }

  if(!visited[height-1][width-1])
    return false;
  return true;
}

int main(){
  ios_base::sync_with_stdio(0);

  while(1){
    cin>>width>>height;
    if(width == 0)
      break;

    cin>>grave_num;
    adj = vector<vector<vector<Vertex>>>(height, vector<vector<Vertex>>(width));
    hole_out = vector<vector<pair<int,int>>>(height, vector<pair<int,int>>(width));
    memset(is_grave, false, sizeof(is_grave));
    memset(is_hole, false, sizeof(is_hole));
    memset(is_exit, false, sizeof(is_exit));
    memset(visited, false, sizeof(visited));
    int r,c;
    for(int i=0; i<grave_num ; ++i){
      cin>>c>>r;
      is_grave[r][c] = true;
    }

    int in_r, in_c, out_r, out_c, time;
    cin>>hole_num;
    for(int i=0; i<hole_num ; ++i){
      cin>>in_c>>in_r>>out_c>>out_r>>time;
      is_hole[in_r][in_c] = true;
      is_exit[out_r][out_c] = true;
      hole_out[in_r][in_c] = {out_r, out_c};
      adj[in_r][in_c].push_back({out_r,out_c,time});
    }

    if(!MakeGraphBFS()){
      cout<<"Impossible\n";
      continue;
    }
    //출발점의 컴포넌트에서 음수 사이클로 이동할 없어도  never가 나옴. 도착점에도 갈 수x

    int result = BellmanFord();
    if(result == -1)
      cout<<"Never\n";
    else if(result >=INF)
      cout<<"Impossible\n";
    else
      cout<<result<<"\n";
  
  }
  return 0;
}
