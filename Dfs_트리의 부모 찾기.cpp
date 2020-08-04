//https://www.acmicpc.net/problem/11725
//평범한  dfs지만 dfs를 모를때라 이상하게 품

#include <iostream>
#include <vector>
#include<string.h>
using namespace std;

vector<int> node[100001];
bool visited[100001];
int parent[100001];


void findParent(int idx){
  visited[idx] = true;
  for(int i=0; i<node[idx].size() ; ++i){
    if(!visited[node[idx][i]]){
      parent[node[idx][i]] =idx;
      findParent(node[idx][i]);
    }
  }
}

int main() {
  int n,f,s;
  ios_base::sync_with_stdio(0);
  cin>>n;

  memset(visited,  false, sizeof(visited));

  for(int i=1; i<n ; ++i){
    cin>>f>>s;
    node[f].push_back(s);
    node[s].push_back(f);
  }

  findParent(1);

  for(int i=2; i<=n ; ++i)
    cout<<parent[i]<<'\n';

  return 0;
}
