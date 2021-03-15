//https://www.acmicpc.net/problem/2150
#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;

int vertex_num, edge_num;
vector<vector<int>> adj;
stack<int> st;
vector<int> visited_order;
vector<bool> is_scc;
vector<vector<int>> sccs;
int order=0;

int FindSCC(int now_idx){
  int min_order = visited_order[now_idx] = ++order;
  int next_idx;
  st.push(now_idx);

  for(int i=0 ; i<adj[now_idx].size() ; ++i){
    next_idx = adj[now_idx][i];
    if(visited_order[next_idx] == -1)
      min_order = min(min_order, FindSCC(next_idx));
    else if(!is_scc[next_idx])
      min_order = min(min_order, visited_order[next_idx]);
  } 
    //DFS 재귀 방문을 마친 후에 간선을 끊을지 검사
  if(min_order == visited_order[now_idx]){
    int temp;
    vector<int> new_scc;
    while(1){
      temp = st.top();
      st.pop();
      is_scc[temp] = true;
      new_scc.push_back(temp);
      if(temp == now_idx)
        break;
    }

    sccs.push_back(new_scc);
  }
  return min_order;
}

bool Comp(vector<int>& va, vector<int>& vb){
  return va[0] < vb[0];
}

int main(){
  ios_base::sync_with_stdio(0);
  cin>>vertex_num>>edge_num;

  adj = vector<vector<int>>(vertex_num+1);
  is_scc = vector<bool>(vertex_num+1, false);
  visited_order = vector<int>(vertex_num+1, -1);

  int u,v;
  for(int i=0; i<edge_num ; ++i){
    cin>>u>>v;
    adj[u].push_back(v);
  }

  for(int idx =1; idx<=vertex_num ; ++idx)
    if(visited_order[idx] == -1)
      FindSCC(idx);
  
  for(int i=0; i<sccs.size() ; ++i)
    sort(sccs[i].begin(), sccs[i].end());

  sort(sccs.begin(), sccs.end(), Comp);

  cout<<sccs.size()<<"\n";
  for(int i=0; i<sccs.size() ; ++i){
    for(int j=0; j<sccs[i].size() ; ++j)
      cout<<sccs[i][j]<<' ';
    cout<<"-1\n";
  }

  return 0;
}
