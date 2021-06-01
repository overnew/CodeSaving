//https://www.acmicpc.net/problem/1420
#include<iostream>
#include<queue>
#include<string.h>
#include<string>
using namespace std;

const int INF = 987654321;
int row, column;
int vertex_num;
char city_map[100][100];
bool visited[100][100];
int change_pos[4][2] = { {0, -1} ,{0,1},{1,0} ,{-1, 0} };

struct Edge{
  int to, capacity,flow;
  Edge* reverse;

  Edge(int _to, int _cap, int _flow =0) : to(_to) , capacity(_cap) {}

  int ResidualCapacity() const{
    return capacity - flow;
  }

  void PushFlow(int amount){
    flow += amount;
    reverse->flow -=amount;
  }
};

vector<vector<Edge*>> adj;

void AddEdge(int u_in, int u_out, int v_in, int v_out){
  Edge* u_out_v_in = new Edge(v_in, INF);
  Edge* v_in_u_out = new Edge(u_out, 0);  //역 방향의 유령 간선

  u_out_v_in->reverse = v_in_u_out;
  v_in_u_out->reverse = u_out_v_in;
  adj[u_out].push_back(u_out_v_in);
  adj[v_in].push_back(v_in_u_out);

  Edge* v_out_u_in = new Edge(u_in, INF);
  Edge* u_in_v_out = new Edge(v_out, 0); //역 방향의 유령 간선

  v_out_u_in->reverse = u_in_v_out;
  u_in_v_out->reverse = v_out_u_in;
  adj[v_out].push_back(v_out_u_in);
  adj[u_in].push_back(u_in_v_out);
}

//source_out에서 출발하여? in에서 인가?
int MinimumCut(int source, int sink){
  int total_flow =0;

  while(1){
    vector<int> parent(vertex_num, -1);
    vector<Edge*> edge_to_child(vertex_num);
    queue<int> q;
    q.push(source);
    parent[source] = source;
    
    while(!q.empty() && parent[sink] == -1){
      int u = q.front();
      q.pop();

      for(int i=0; i<adj[u].size() ; ++i){
        Edge* uv = adj[u][i];
        int v = uv->to;
        if(uv->ResidualCapacity() >0 && parent[v] == -1){
          q.push(v);
          parent[v] = u;
          edge_to_child[v] = uv;
        }
      }
    }

    if(parent[sink] == -1)
      break;

    int amount = INF;
    for(int p = sink ; p!= source ;p = parent[p]){
      Edge* parent_to_p = edge_to_child[p];
      amount = min(amount, parent_to_p->ResidualCapacity());
    }

    for(int p = sink ; p!= source ;p = parent[p]){
      Edge* parent_to_p = edge_to_child[p];
      parent_to_p->PushFlow(amount);
    }

    total_flow += amount;
  }
  return total_flow;
}

int main(){
  ios_base::sync_with_stdio(0);
  cin>>row>>column;

  vertex_num = row*column*2;
  adj = vector<vector<Edge*>>(vertex_num);

  //정점 분할을 위해 같은 정점의 in과 out을 이어줌
  for(int i=0; i<vertex_num ; i+=2){
    Edge* in_out = new Edge(i+1, 1);  
    //out에서 in으로는 간선이 없으므로 역방향의 용량은 0
    Edge* out_in = new Edge(i, 0);  

    //서로를 역방향 간선으로 저장
    in_out->reverse = out_in;
    out_in->reverse = in_out;

    adj[i].push_back(in_out);
    adj[i+1].push_back(out_in);
  }

  string temp;
  pair<int,int> source_pos = {-1,-1}, sink_pos = {-1,-1};
  for(int r=0; r<row ; ++r){
    cin>>temp;
    for(int c=0; c<column ; ++c){
      city_map[r][c] = temp[c];
      if(city_map[r][c] == 'K')
        source_pos = {r,c};
      else if(city_map[r][c] == 'H')
        sink_pos = {r,c};
    }
  }

  //K와 H가 둘다 존재하는지
  if(source_pos.first == -1 || sink_pos.first == -1){
    cout<<"-1\n";
    return 0;
  }

  //K와 H가 바로 옆에 붙어있는지
  int r,c;
  for(int i=0; i<4 ; ++i){
    r = source_pos.first + change_pos[i][0];
    c = source_pos.second + change_pos[i][1];

    if(r == sink_pos.first && c== sink_pos.second){
      cout<<"-1\n";
      return 0;
    }
  }

  memset(visited, false, sizeof(visited));

  //인접 좌표의 그래프 연결
  int next_r, next_c;
  for(int r=0; r<row ; ++r){
    for(int c=0; c<column ; ++c){
      if(city_map[r][c] == '#')
        continue;
      visited[r][c] = true;

      int u_in = ((r*column) + c)*2, u_out = u_in+1;
      for(int i =0; i<4 ; ++i){
        next_r = r+ change_pos[i][0];
        next_c = c+ change_pos[i][1];

        //범위 확인
        if(next_r < 0 || row <= next_r || next_c < 0 || column <= next_c)
          continue;

        if(city_map[next_r][next_c] == '#')
          continue;

        if(!visited[next_r][next_c]){
          int v_in = ((next_r*column) + next_c)*2, v_out = v_in+1;
          AddEdge(u_in, u_out,v_in, v_out);
        }
      }

    }
  }

  int source_out = ((source_pos.first * column) + source_pos.second) *2 +1;
  int sink_in = ((sink_pos.first * column) + sink_pos.second) *2;
  cout<<MinimumCut(source_out, sink_in)<<"\n";

  return 0;
}
