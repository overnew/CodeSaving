//https://www.acmicpc.net/problem/5719
#include<iostream>
#include<queue>
#include<vector>
#include<string.h>
#include<string>
using namespace std;

typedef priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pair_pq;

struct EdgeInfo{  //간선 정보 저장
  int to;
  int cost;
  int edge_idx;
};

struct DistInfo{  //거리 정보 저장
  int cost;
  int parent;
  int edge_idx;

  bool operator<(const DistInfo& x) const{
    return cost > x.cost;
  }
};

int vertex_num, edge_num;
int start_idx, dest_idx;
vector<vector<EdgeInfo>> adj;
vector<priority_queue<DistInfo>> vertex_pq;
bool is_delete[10001];

int Dijkstra(){
  pair_pq pq;
  vector<int> dist(500, INT32_MAX);

  pq.push({0,start_idx});
  dist[start_idx] = 0;

  int idx, cost, next_idx, next_cost;
  while(!pq.empty()){
    idx = pq.top().second;
    cost = pq.top().first;
    pq.pop();

    if(dist[idx] < cost)
      continue;
    
    for(int i=0 ; i<adj[idx].size() ; ++i){
      if(is_delete[adj[idx][i].edge_idx])
        continue;

      next_idx = adj[idx][i].to;
      next_cost = cost + adj[idx][i].cost;

      if(next_cost < dist[next_idx]){
        pq.push({next_cost, next_idx});
        dist[next_idx] = next_cost;
      }

    }
  }

  if(dist[dest_idx] == INT32_MAX)
    return -1;
  
  return dist[dest_idx];
}

void DeleteMinPath(){ //최단 경로들에 포함된 간선들을 제거
  vertex_pq = vector<priority_queue<DistInfo>>(vertex_num);  //cost와 parent의 idx저장
  pair_pq pq;

  pq.push({0,start_idx});
  vertex_pq[start_idx].push({0,start_idx,0});

  int idx, cost, next_idx, next_cost, edge_idx;
  while(!pq.empty()){
    idx = pq.top().second;
    cost = pq.top().first;
    pq.pop();

    if(!vertex_pq[idx].empty() && vertex_pq[idx].top().cost < cost)
      continue;

    for(int i=0 ; i<adj[idx].size() ; ++i){
      next_idx = adj[idx][i].to;
      next_cost = cost + adj[idx][i].cost;
      edge_idx = adj[idx][i].edge_idx;

      if(vertex_pq[next_idx].empty() || next_cost <= vertex_pq[next_idx].top().cost){
        if(!vertex_pq[next_idx].empty() && next_cost < vertex_pq[next_idx].top().cost)  // 정점의 pq의top보다 cost가 작은 경우만 push
        //작거나 같을때 모두 push할 경우 메모리가 초과됨. 중복을 없앤다.
          pq.push({next_cost, next_idx});
        else if(vertex_pq[next_idx].empty())  //정점의 pq가 비어있다면 push
          pq.push({next_cost, next_idx});
        vertex_pq[next_idx].push({next_cost,idx, edge_idx});
      }

    }
    
  }

  //bfs로 간선의 제거
  vector<bool> is_in_que(501,false);
  queue<int> que;
  que.push(dest_idx);
  is_in_que[dest_idx] = true;
  
  int top_cost, now_idx, top_parnet;
  while(!que.empty()){
    now_idx = que.front();
    que.pop();

    if(vertex_pq[now_idx].empty())
      continue;
    
    top_cost = vertex_pq[now_idx].top().cost;

    while(!vertex_pq[now_idx].empty() && vertex_pq[now_idx].top().cost <= top_cost){  // 간선의 pq에서 top cost와 같은 간선은 모두 제거

      top_parnet =  vertex_pq[now_idx].top().parent;

      is_delete[vertex_pq[now_idx].top().edge_idx] = true;
      vertex_pq[now_idx].pop();

      if(is_in_que[top_parnet]) //이미 큐에 들어있는 경우 중복을 제거하기 위해 삽입 하지 않는다.
        continue;
        
      que.push(top_parnet);
      is_in_que[top_parnet] = true;
    }

  }
  
}

int main(){
  ios_base::sync_with_stdio(0);

  while(1){
    cin>>vertex_num>>edge_num;
    if(vertex_num == 0) //테스트 종료
      break;

    adj = vector<vector<EdgeInfo>>(vertex_num);
    cin>>start_idx>>dest_idx;

    int u,v,cost, order =1;
    for(int i=0 ; i<edge_num ; ++i){
      cin>>u>>v>>cost;
      adj[u].push_back({v,cost,order++});
    }
    memset(is_delete, false, sizeof(is_delete));

    DeleteMinPath();
    cout<<Dijkstra()<<'\n';
  }

  return 0;
}
