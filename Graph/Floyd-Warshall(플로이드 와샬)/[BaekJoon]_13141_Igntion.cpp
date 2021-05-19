//https://www.acmicpc.net/problem/13141
#include<vector>
#include<cstdio>
using namespace std;

const int INF = 987654321;
int vertex_num, edge_num;
vector<vector<int>> adj, dist;

double BurnGraph(){
  double shortest_time = INF, longest_time, spent_time, remain_len;
  int edge_len;

  for(int start=1; start<=vertex_num ; ++start){
    longest_time = 0;

    for(int from = 1; from<=vertex_num ; ++from){
      for(int to =1; to<=vertex_num ; ++to){
        edge_len = adj[from][to];

        if(edge_len != -1){
          remain_len = edge_len -(dist[start][from] - dist[start][to]);
          if(remain_len >0){
            spent_time = (remain_len/2) + dist[start][from];
            longest_time = max( spent_time,longest_time);
          }

        }

      }
    }
    shortest_time = min(longest_time, shortest_time);
  }
  return shortest_time;
} 

void Floyd(){
  for(int k=1; k<=vertex_num ; ++k)
    for(int i=1; i<=vertex_num ; ++i)
      for(int j=1; j<=vertex_num ; ++j)
        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
}

int main(){
  scanf("%d %d", &vertex_num, &edge_num);
  adj = vector<vector<int>>(vertex_num+1, vector<int>(vertex_num+1, -1));
  dist = vector<vector<int>>(vertex_num+1, vector<int>(vertex_num+1, INF));

  for(int i=1; i<=vertex_num ; ++i)
    dist[i][i] = 0;

  int S,E,L;
  for(int i=0; i<edge_num ; ++i){
    scanf("%d %d %d", &S, &E, &L);
    if(adj[S][E] == -1 || adj[S][E] < L){
      adj[S][E] = L;
      adj[E][S] = L;
    }
    if(dist[S][E] == INF || L < dist[S][E]){
      dist[S][E] = L;
      dist[E][S] = L;
    }
  }

  Floyd();

  printf("%.1f\n", BurnGraph());

  return 0;
}
