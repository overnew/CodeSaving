//https://www.acmicpc.net/problem/2188
#include<iostream>
#include<queue>
#include<string.h>
using namespace std;

int cow_num, house_num;
vector<vector<int>> adj;
vector<int> a_match, b_match, visited;

bool DFS(int a){
  if(visited[a])
    return  false;
  visited[a] = true;

  for(int i=0; i<adj[a].size() ; ++i){
    int b = adj[a][i];
    if(b_match[b] == -1 || DFS(b_match[b])){
      a_match[a] = b;
      b_match[b] = a;
      return true;
    }
  }
  return false;
}

int main(){
  ios_base::sync_with_stdio(0);
  cin>>cow_num>>house_num;
  adj = vector<vector<int>>(cow_num);

  int hope_num, house_idx;
  for(int i=0; i< cow_num ; ++i){
    cin>>hope_num;
    for(int j=0;j<hope_num; ++j){
      cin>>house_idx;
      adj[i].push_back(house_idx);
    }
  }

  a_match = vector<int>(cow_num, -1);
  b_match = vector<int>(house_num+1, -1);

  int max_matching =0;
  for(int start = 0; start<cow_num ; ++start){
    visited = vector<int>(cow_num, false);
    if(DFS(start))
      ++max_matching;
  }

  cout<<max_matching<<'\n';
  return 0;
}
