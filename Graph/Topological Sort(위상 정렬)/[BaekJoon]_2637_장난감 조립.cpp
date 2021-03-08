//https://www.acmicpc.net/problem/2637
#include<iostream>
#include<queue>
#include<string.h>
using namespace std;

int main(){
  ios_base::sync_with_stdio(0);

  int part[101][101];
  int part_num,relation_num;
  vector<int> adj[101]; //directed edge
  int indegree[101];    //진입 차수
  bool is_base[101];    //기본 부품인지

  memset(part, 0 , sizeof(part));
  memset(adj, 0 , sizeof(adj));
  memset(indegree, 0, sizeof(indegree));
  memset(is_base, false, sizeof(is_base));

  cin>>part_num>>relation_num;

  int part_idx, need_idx, need_num;
  while(relation_num--){
    cin>>part_idx>>need_idx>>need_num;
    part[part_idx][need_idx] = need_num;
    adj[need_idx].push_back(part_idx);
    ++indegree[part_idx];
  }

  queue<int> que;
  int base_part_cnt =0;
  for(int i=1; i<=part_num ; ++i){
    if(indegree[i]==0){
      que.push(i);
      is_base[i] = true;
      ++base_part_cnt;
    }
  }

  for(int i=0; i<part_num ; ++i){ //노드의 개수만큼 진행
    part_idx = que.front();
    que.pop();

    if(!is_base[part_idx]){
      for(int j=1; j<=part_num ; ++j){

        if(!is_base[j] && part[part_idx][j] !=0){
          for(int k=1; k<=part_num ; ++k)
            if(is_base[k] && part[j][k] != 0)
              part[part_idx][k] += (part[j][k] * part[part_idx][j]);

          part[part_idx][j] =0;
        }

      }
    }

    for(int j=0; j<adj[part_idx].size() ; ++j)
      if(--indegree[adj[part_idx][j]] == 0)
        que.push(adj[part_idx][j]);       
  }

  for(int i=1; i<=part_num ; ++i)
    if(part[part_num][i])
      cout<<i<<' '<<part[part_num][i]<<"\n";

  return 0;
}
