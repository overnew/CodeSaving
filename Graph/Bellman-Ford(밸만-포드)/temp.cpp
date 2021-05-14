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
bool is_grave[300][300], is_hole[300][300], is_exit[300][300];
bool visited[300][300];
int change_pos[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};
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
  q.push({0,0});
  visited[0][0] = true;

  for(int i=0; i<height ; ++i){
    for(int j=0; j<width ; ++j){
      if(is_exit[i][j]){
        q.push({i,j});
        visited[i][j] = true;
      }
        
    }
  }

  int now_r, now_c,next_r ,next_c;
  while(!q.empty()){
    now_r = q.front().first;
    now_c = q.front().second;
    q.pop();

    for(int i=0; i<4 ; ++i){
      next_r = now_r + change_pos[i][0];
      next_c = now_c + change_pos[i][1];
      if(next_r<0 || height<= next_r || next_c<0 || width<=next_c)
        continue;

      if(visited[next_r][next_c] || is_grave[next_r][next_c])
        continue;

      visited[next_r][next_c] = true;
      q.push({next_r, next_c});
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
      adj[in_r][in_c].push_back({out_r,out_c,time});
    }
    
    if(!MakeGraphBFS()){
      cout<<"Impossible\n";
      continue;
    }

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
