//https://www.acmicpc.net/problem/2610
#include<iostream>
#include<string.h>
#include<algorithm>
#include<queue>
using namespace std;

const int INF = 987654321;
int people_num, relation_num;
vector<vector<int>> dist;
bool visited[101], is_in_que[101];
int committee_order = 0;
vector<vector<int>> committee_member;

void FindCommitteeBFS(int start_idx){
  queue<int> q;
  vector<int> new_committee;  //이번에 생성하는 위원회의 멤버를 저장
  new_committee.push_back(start_idx);

  q.push(start_idx);
  is_in_que[start_idx] = true;
  visited[start_idx] =true;

  int idx;
  while(!q.empty()){
    idx = q.front();
    q.pop();
    visited[idx] = true;

    for(int i=1; i<= people_num ; ++i){
      //방문하지 않았거나 큐에 삽입되지 않은 정점만 확인
      if(!visited[i] && !is_in_que[i])
        if(dist[idx][i] < INF){ //dist가 INF라면 idx와 i정점은 서로 도달 불가
          q.push(i);
          is_in_que[i] = true;
          new_committee.push_back(i); //위원회 멤버로 추가
        }

    }
  }

  committee_member.push_back(new_committee); //새로운 위원회를 삽입
}

void FloydWarshall(){
  for(int k=1; k<=people_num ; ++k)
    for(int i=1; i<=people_num ; ++i)
      for(int j=1; j<=people_num ; ++j)
        dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);
}

int main(){
  ios_base::sync_with_stdio(0);
  cin>>people_num>>relation_num;

  dist = vector<vector<int>>(people_num+1, vector<int>(people_num+1, INF));
  for(int i=1; i<=people_num ; ++i)
    dist[i][i] = 0;

  int u,v;
  for(int i=0; i<relation_num ; ++i){
    cin>>u>>v;
    dist[u][v]= dist[v][u] = 1;
  }

  FloydWarshall();

  memset(visited, false, sizeof(visited));
  memset(is_in_que, false , sizeof(is_in_que));

  for(int i=1; i<=people_num ; ++i)
    //관계가 이어지는 사람끼리만 위원회를 만듬
    if(!visited[i]){
      FindCommitteeBFS(i);
      ++committee_order;
    }

  vector<int> representives;
  int now_idx, next_idx;
  for(int k=0; k<committee_order ; ++k){
    pair<int,int> represent_info(0,INF);   //K번째 위원회의 대표의 정보

    for(int i=0; i<committee_member[k].size() ; ++i){
      int max_dist = 0; //now_idx와 다른 정점들 사이의 가장 먼 거리를 저장
      now_idx = committee_member[k][i];

      for(int j=0; j<committee_member[k].size() ; ++j){
        next_idx =committee_member[k][j];
        max_dist = max(dist[now_idx][next_idx], max_dist);
      }

      //현재 대표의 의사 전달시간 보다 작은 경우 새로운 대표로 선택
      if(max_dist < represent_info.second)  
        represent_info = {now_idx, max_dist};
    }
    representives.push_back(represent_info.first);
  }

  sort(representives.begin(), representives.end());

  cout<<committee_order<<"\n";
  for(int i=0; i<representives.size() ; ++i)
    cout<<representives[i]<<"\n";

  return 0;
}
