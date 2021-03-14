//https://www.acmicpc.net/problem/11400
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

int vertex_num, edge_num;
vector<vector<int>> adj;
vector<int> visited_order;
vector<pair<int,int>> bridge;
int order =0, bridge_cnt=0;

int FindCutVertex(int now_idx, int parent_idx){
  visited_order[now_idx] = ++order;
  
  int min_order = visited_order[now_idx];
  int subtree_min_order,next_idx;
  int a,b;

  for(int i=0; i<adj[now_idx].size() ; ++i){
    next_idx = adj[now_idx][i];
    if(visited_order[next_idx] == -1){
      subtree_min_order = FindCutVertex(next_idx, now_idx);
      
      if(subtree_min_order > visited_order[now_idx]){
        a=now_idx; b = next_idx;
        if(a > b) swap(a,b);

        bridge.push_back(make_pair(a,b ));
        bridge_cnt++;
      }
        
      min_order = min(min_order, subtree_min_order);
    }else{
      if(next_idx != parent_idx)
        min_order = min(min_order, visited_order[next_idx]);
    }
  }

  return min_order;
}

int main(){
  scanf("%d %d", &vertex_num, &edge_num);
  adj = vector<vector<int>>(vertex_num+1);
  visited_order = vector<int>(vertex_num+1, -1);

  int u,v;
  for(int i=0; i<edge_num ; ++i){
    scanf("%d %d",&u, &v);
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  for(int idx=1; idx<=vertex_num ; ++idx)
    if(visited_order[idx] == -1)
      FindCutVertex(idx,0);

  printf("%d\n", bridge_cnt);
  sort(bridge.begin(), bridge.end());

  for(int i=0; i<bridge.size() ; ++i)
    printf("%d %d\n",bridge[i].first, bridge[i].second);

  return 0;
}
