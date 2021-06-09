//https://www.acmicpc.net/problem/11495
#include<iostream>
#include<queue>
#include<string.h>
using namespace std;

const int MAXN = 2503, INF = 987654321;
int row, column;
int total_value, vertex_num;
int board[50][50];
int capacity[MAXN][MAXN], flow[MAXN][MAXN];
int change_pos[4][2]= {{1,0}, {-1,0}, {0,1}, {0,-1}};
vector<vector<int>> adj;

int MaximumFlow(int source, int sink){
  int total_flow = 0;

  while(1){
    vector<int> parent(vertex_num, -1);
    queue<int> q;
    parent[source] = source;
    q.push(source);

    while(!q.empty() && parent[sink] == -1){
      int u = q.front();
      q.pop();

      //인접 정점만 검사
      for(int i=0; i<adj[u].size() ; ++i){
        int v = adj[u][i];
        if(capacity[u][v] - flow[u][v] >0 && parent[v] == -1){
          q.push(v);
          parent[v] = u;
        }
      }
    }

    //더이상 증가 경로가 없는 경우
    if(parent[sink] == -1)
      break;
    
    int amount = INF;
    for(int p = sink; p != source ; p = parent[p])
      amount = min(capacity[parent[p]][p] - flow[parent[p]][p], amount);
    
    for(int p = sink; p != source ; p = parent[p]){
      flow[parent[p]][p] += amount;
      flow[p][parent[p]] -= amount; //역 방향은 -flow
    }

    total_flow += amount;
  }

  return total_flow;
}

int main(){
  ios_base::sync_with_stdio(0);
  int test_num;

  cin>>test_num;

  while(test_num--){
    cin>>row>>column;
    memset(capacity, 0, sizeof(capacity) );
    memset(flow, 0, sizeof(flow) );
    total_value = 0, vertex_num = 2+ row*column;
    adj = vector<vector<int>>(vertex_num);

    int order =2;
    bool is_red = true;
    for(int r = 0; r<row ; ++r){
      for(int c = 0; c<column ; ++c){
        cin>>board[r][c];
        total_value += board[r][c];

        //red라면 source와 연결
        if(is_red){
          capacity[0][order] = board[r][c];
          adj[0].push_back(order); 
          adj[order].push_back(0); 
        }
        //blue라면 sink와 연결
        else{
          capacity[order][1] = board[r][c];
          adj[order].push_back(1); 
          adj[1].push_back(order); 
        }
        ++order;
        is_red = !is_red;
      }
      //열이 짝수라면 다음 칸은 red
      if(column%2 == 0)
        is_red = !is_red;
    }
    
    int change_order[4]= {column, -column, 1, -1};
    int blue_r, blue_c, blue_order;
    order = 2;
    is_red = true;

    //red정점과 상하좌우칸을 연결
    for(int r = 0; r<row ; ++r){
      for(int c = 0; c<column ; ++c){
        if(is_red)
          for(int i=0; i<4 ; ++i){
            blue_r = r + change_pos[i][0];
            blue_c = c + change_pos[i][1]; 

            //범위 확인
            if(blue_r < 0 || row <= blue_r|| blue_c <0 || column <= blue_c)
              continue;
            
            blue_order = order + change_order[i];
            capacity[order][blue_order] = INF;
            adj[order].push_back(blue_order);
            adj[blue_order].push_back(order);
          }
        is_red = !is_red;
        ++order;
      }
      if(column%2 == 0)
        is_red = !is_red;
    }

    int total_flow = MaximumFlow(0, 1);
    cout<<total_value - total_flow<<'\n';
  }

  return 0;
}
