//https://www.acmicpc.net/problem/1238
#include<iostream>
#include<queue>
#include<vector>
using namespace std;

const int MAXCOST = 1000001;
int student_num, road_num;

vector<int> Dijkstra(int start_node, vector<vector<pair<int,int>>>& adj){
  priority_queue<pair<int,int>, vector<pair<int,int>> , greater<pair<int,int>>> pq;
  vector<int> dist(student_num+1,MAXCOST);
  dist[start_node] = 0;
  pq.push(make_pair(0, start_node));

  int cost, now_node, next_node,next_dist;
  while(!pq.empty()){
    now_node = pq.top().second;
    cost = pq.top().first;
    pq.pop();

    if( dist[now_node] < cost )
      continue;

    for(int i=0; i<adj[now_node].size() ; ++i){
      next_node = adj[now_node][i].second;
      next_dist = cost + adj[now_node][i].first;
      if(dist[next_node] > next_dist){
        dist[next_node] = next_dist;
        pq.push(make_pair(next_dist,next_node ));
      }
    }

  }

  return dist;
} 

int main(){
  ios_base::sync_with_stdio(0);
  int dest_town;
  cin>>student_num>>road_num>>dest_town;
  vector<vector<pair<int,int>>> adj(student_num+1);
  vector<vector<pair<int,int>>> re_adj(student_num+1);

  int u,v, cost;
  for(int i=0; i<road_num ; ++i){
    cin>>u>>v>>cost;
    adj[u].push_back(make_pair(cost, v));
    re_adj[v].push_back(make_pair(cost, u)); //역 방향으로 만들어줌
  }

  vector<int> departure_dist = Dijkstra(dest_town, re_adj);
  vector<int> arrival_dist = Dijkstra(dest_town, adj);

  int max_dist = 0;
  for(int i=1; i<=student_num ; ++i)
    max_dist = max(max_dist, arrival_dist[i]+ departure_dist[i]);

  cout<<max_dist<<'\n';

  return 0;
}
