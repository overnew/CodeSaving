//https://www.acmicpc.net/problem/10265
#include<iostream>
#include<string.h>
#include<vector>
#include<stack>
using namespace std;

int people_num, bus_capacity;
vector<vector<int>> adj;
vector<int> visited,scc_label;
vector<int> scc_indegree,scc_size;
stack<int> st;
vector<pair<int,int>> component_min_max;
int dp[1001][1001];
int order =0, scc_order =0, component_order =0;

int FindSCC(int idx){
  int min_order = visited[idx] = order++;
  st.push(idx);

  int next_idx;
  for(int i=0; i<adj[idx].size() ; ++i){
    next_idx = adj[idx][i];

    if(visited[next_idx] == -1){
      min_order = min(min_order, FindSCC(next_idx));

      if(scc_label[next_idx] != -1)
        scc_indegree[scc_label[next_idx]]++;
    }
    else if(scc_label[next_idx]== -1)
      min_order = min(min_order, visited[next_idx]);
    else
      scc_indegree[scc_label[next_idx]]++;
    
  }

  if(min_order == visited[idx]){
    int temp, size =0;
    while(1){
      temp = st.top();
      st.pop();
      scc_label[temp] = scc_order;
      size++;
      if(temp == idx)
        break;
    }
    scc_size[scc_order] =size;
    ++scc_order;
  }

  return min_order;
}

void TarjanSCC(){
  visited = vector<int>(people_num+1, -1);
  scc_label = vector<int>(people_num+1 , -1);
  scc_indegree = vector<int>(people_num+1, 0);
  scc_size = vector<int>(people_num +1, 0);

  for(int i=1; i<=people_num ; ++i)
    if(visited[i] == -1)
      FindSCC(i);
}

int MakeMaxMinOfComponent(int idx, bool is_root, int parent_scc){ 
  visited[idx] = true;

  int ret =0;
  if(is_root)
    ret = component_min_max[component_order].first = scc_size[scc_label[idx]];
  
  if(parent_scc != scc_label[idx])
    ret = scc_size[scc_label[idx]];

  int next_idx;
  for(int i=0 ; i<adj[idx].size() ; ++i){
    next_idx = adj[idx][i];
    if(visited[next_idx] == false)
      ret += MakeMaxMinOfComponent(next_idx, false, scc_label[idx]);
  }

  if(is_root)
    component_min_max[component_order].second = ret;

  return ret;
}

int KnapsackDFS(int component_idx, int remain_cap){
  if(component_idx >=component_order)
    return 0;

  int& ret = dp[component_idx][remain_cap];
  if(ret != -1)
    return ret;

  ret = KnapsackDFS(component_idx+1,remain_cap );
  for(int i=component_min_max[component_idx].first; i<=component_min_max[component_idx].second ; ++i){
    if(i>remain_cap)
      break;
    ret = max(ret, KnapsackDFS(component_idx+1,remain_cap-i ) + i);
  }
  return ret;
}

int main(){
  ios_base::sync_with_stdio(0);
  cin>>people_num>>bus_capacity;
  adj = vector<vector<int>>(people_num+1);

  int pick;
  for(int idx=1; idx<=people_num ; ++idx){
    cin>>pick;
    adj[pick].push_back(idx);
  }
 
  TarjanSCC();

  component_min_max = vector<pair<int,int>>(scc_order);
  visited = vector<int>(people_num+1, false);
  for(int idx=1; idx<=people_num ; ++idx){
    if(scc_indegree[scc_label[idx]]==0 && visited[idx] == false){
      MakeMaxMinOfComponent(idx, true,scc_label[idx]);
      ++component_order;
    }
  }

  memset(dp, -1 ,sizeof(dp) );
  cout<<KnapsackDFS(0,bus_capacity)<<'\n';

  return 0;
}
