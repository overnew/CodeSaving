//https://www.acmicpc.net/problem/1761
#include <iostream>
#include<vector>
#include<cstdio>
#include<string.h>
using namespace std;

int node_num;
const int TREE_HIGTH = 20;
int depth[40001];
int parent[40001][TREE_HIGTH];
int dist[40001][TREE_HIGTH];
vector<pair<int,int>> adj[40001];

void FindParent(int par, int now, int dep, int cost){
  
  depth[now] = dep;
  parent[now][0] = par;
  dist[now][0] = cost;

  for(int i=0; i<adj[now].size() ; ++i){
    if(adj[now][i].first != par)
      FindParent(now, adj[now][i].first, dep+1,adj[now][i].second);
  }
  return;
}

int DistNodePair(int a, int b){
  int sum=0;
  if(depth[a] != depth[b]){
    if(depth[a] < depth[b]) //깊이가 다르다면 a가 항상 더 깊게
      swap(a,b);
    
    int dif = depth[a] - depth[b];
    for(int i=0; dif>0 ; ++i){
      if(dif %2 ==1){
        sum += dist[a][i];
        a = parent[a][i];
      }
      dif = dif>>1;
    }
  }

  if(a != b){
    for(int k = TREE_HIGTH-1; k>=0 ; --k){
      if(parent[a][k] != 0 && parent[a][k] != parent[b][k]){
        sum+= (dist[a][k] + dist[b][k]);
        a = parent[a][k];
        b = parent[b][k];
      }
    }

    sum += dist[a][0] + dist[b][0];
  }
  
  return sum;
}

int main(){
  scanf("%d",&node_num);

  int a,b,cost;
  for(int i=0; i<node_num-1 ; ++i){
    scanf("%d %d %d",&a, &b, &cost);
    adj[a].push_back(make_pair(b, cost));
    adj[b].push_back(make_pair(a, cost));
  }

  memset(parent, 0 , sizeof(parent));
  memset(dist, 0, sizeof(dist));

  FindParent(0, 1,0,0);

  for(int k=1; k<TREE_HIGTH ; ++k){
    for(int idx = 2 ; idx<=node_num ; ++idx){
      if(parent[idx][k-1] != 0){
        parent[idx][k] = parent[parent[idx][k-1]][k-1];
        dist[idx][k] = dist[idx][k-1] + dist[parent[idx][k-1]][k-1];
      }
    }
  }

  int pair_num;
  scanf("%d", &pair_num);

  while(pair_num--){
    scanf("%d %d", &a,&b);
    printf("%d\n",DistNodePair(a,b));
  }

  return 0;
}
