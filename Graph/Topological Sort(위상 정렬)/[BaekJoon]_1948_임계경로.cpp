//https://www.acmicpc.net/problem/1948
#include<iostream>
#include<queue>
#include<string.h>
using namespace std;

int main(){
  ios_base::sync_with_stdio(0);
  int city_num, road_num;
  cin>>city_num>>road_num;

  vector<vector<pair<int,int>>> adj_time(city_num+1);
  vector<vector<pair<int,int>>> reverse_adj(city_num+1);
  vector<int> max_arrival_time(city_num+1,0);
  vector<int> indegree(city_num+1,0);
  vector<int> re_indegree(city_num+1,0);
  vector<bool> visited(city_num+1, false);

  int start_idx, dest_idx, time_cost;
  for(int i=0; i<road_num ; ++i){
    cin>>start_idx>>dest_idx>>time_cost;
    adj_time[start_idx].push_back(make_pair(dest_idx, time_cost));
    reverse_adj[dest_idx].push_back(make_pair(start_idx, time_cost));
    ++indegree[dest_idx];
    ++re_indegree[start_idx];
  }

  int start_city, dest_city;
  cin>>start_city>>dest_city;
  queue<int> que; //큐에 들어가는 도시는 간선이 모두 제거되어 도착 최대 시간을 저장하고 있는 경우
  que.push(start_city);
  
  int now_city_idx;
  for(int idx=0; idx<city_num ; ++idx){
    now_city_idx = que.front();
    que.pop();

    for(int i=0; i<adj_time[now_city_idx].size() ; ++i){
      dest_idx = adj_time[now_city_idx][i].first;
      time_cost = adj_time[now_city_idx][i].second;

      --indegree[dest_idx];
      max_arrival_time[dest_idx] = max(max_arrival_time[dest_idx] ,max_arrival_time[now_city_idx] + time_cost );

      if(indegree[dest_idx]==0)
        que.push(dest_idx);
    }
  }

  queue<int> re_que;
  re_que.push(dest_city);
  
  int road_cnt=0;
  while(1){
    now_city_idx = re_que.front();
    re_que.pop();

    if(now_city_idx == start_city)
      break;

    for(int i=0; i<reverse_adj[now_city_idx].size() ; ++i){
      dest_idx = reverse_adj[now_city_idx][i].first;
      time_cost = reverse_adj[now_city_idx][i].second;

      if(max_arrival_time[now_city_idx] - max_arrival_time[dest_idx] ==time_cost){
        ++road_cnt;
        if(!visited[dest_idx]){
          visited[dest_idx] = true;
          re_que.push(dest_idx);
        }
      }

    }
  }  
  cout<<max_arrival_time[dest_city]<<'\n'<<road_cnt<<"\n";

  return 0;
}
