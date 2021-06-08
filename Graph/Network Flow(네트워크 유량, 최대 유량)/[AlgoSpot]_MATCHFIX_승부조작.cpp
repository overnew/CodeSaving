//https://algospot.com/judge/problem/read/MATCHFIX
#include<iostream>
#include<queue>
#include<string.h>
using namespace std;

const int INF = 987654321;
const int MAXN = 120;
int vertex_num;
int player_num, match_num;
int wins[12], match[100][2];
int capacity[MAXN][MAXN], flow[MAXN][MAXN];

int MinimumCut(int source, int sink){
  int total_flow = 0;

  while(1){
    vector<int> parent(vertex_num, -1);
    queue<int> q;
    parent[source] = source;
    q.push(source);

    while(!q.empty() && parent[sink] == -1){
      int u = q.front();
      q.pop();

      for(int v=0; v<vertex_num ; ++v)
        if(capacity[u][v] - flow[u][v] >0 && parent[v] == -1){
          q.push(v);
          parent[v] = u;
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

int WinWith(int max_win){
  capacity[2+match_num][1] = max_win - wins[0];

  for(int i=1; i<player_num ; ++i){
    capacity[2+match_num+i][1] = (max_win - 1) - wins[i];

    if(capacity[2+match_num+i][1] < 0)
      return -1;
  }

  return MinimumCut(0, 1);
}

int Solve(int lower, int upper){
  int ret = -1;
  int remain_flow = match_num;
  for(int max_win = lower; max_win<=upper  ; ++max_win){
    int new_flow = WinWith(max_win);
    if(new_flow == -1)
      continue;

    remain_flow -= new_flow;
    if(remain_flow == 0)
      return max_win;
  }
  return ret;
}

int main(){
  ios_base::sync_with_stdio(0);
  int test_num;
  cin>>test_num;

  while(test_num--){
    cin>>player_num>>match_num;
    vertex_num = 2 + player_num + match_num;

    memset(capacity, 0, sizeof(capacity));
    memset(flow, 0, sizeof(flow));

    int biggest = 0;
    for(int i=0; i<player_num ; ++i){
      cin>>wins[i];
      biggest = max(biggest, wins[i]);
    }

    int u, v, Xmatch_cnt=0;
    for(int i=0; i<match_num ; ++i){
      cin>>u>>v;
      match[i][0] = u; 
      match[i][1] = v;
      if(u == 0 || v == 0)
        Xmatch_cnt++;
    }

    for(int i =0; i<match_num ; ++i){
      //source에서 경기로
      capacity[0][i+2] =1;

      //경기에서 선수로
      for(int j=0; j<2 ; ++j)
        capacity[i+2][2+ match_num + match[i][j]] = 1;
    }
    
    //승리의 하한은 결승 전까지이긴 승리의 개수
    int lower_bound = wins[0];
    //승리의 상한은 결승에서 X가 자신의 경기를 모두 이긴 경우
    int upper_bound = wins[0] + Xmatch_cnt;

    cout<<Solve(lower_bound, upper_bound)<<'\n';
  }

  return 0;
}
