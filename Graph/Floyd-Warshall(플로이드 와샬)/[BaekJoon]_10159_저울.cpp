//https://www.acmicpc.net/problem/10159
#include<iostream>
#include<vector>
#include<string.h>
using namespace std;

int object_num, pair_num;
bool is_adj[101][101];

void Floyd(){
  for(int k=1; k<=object_num ; ++k)
    for(int i=1; i<=object_num ; ++i)
      for(int j=1; j<=object_num ; ++j)
        is_adj[i][j] = is_adj[i][j] || (is_adj[i][k] && is_adj[k][j]);
      
}

int main(){
  ios_base::sync_with_stdio(0);
  cin>>object_num>>pair_num;

  memset(is_adj, false , sizeof(is_adj));
  for(int i=1; i<=object_num ;++i)
    is_adj[i][i]= true;

  int u,v;
  for(int i=0; i<pair_num ; ++i){
    cin>>u>>v;
    is_adj[u][v] = true;
  }

  Floyd();

  for(int i=1; i<=object_num ; ++i ){
    int cnt =0;
    for(int j=1; j<=object_num ; ++j){
      if(!(is_adj[i][j] || is_adj[j][i]))
        ++cnt;
    }
    cout<<cnt<<'\n';
  }

  return 0;
}
