//https://www.acmicpc.net/problem/5214
#include<iostream>
#include<queue>
#include<string.h>
#include<vector>
using namespace std;

int station_num, linked_num,hyper_tube_num ;
vector<vector<int>> adj;
int passed_station[101001];

int HyperBFS(){
  queue<int> que;
  que.push(1);
  passed_station[1] = 1;

  int station_idx;
  while(!que.empty()){
    station_idx = que.front();
    que.pop();

    if(station_idx == station_num)
      return passed_station[station_idx];
    
    int next_station, next_cost = passed_station[station_idx]+1;
    for(int i=0; i< adj[station_idx].size() ; ++i){
      next_station = adj[station_idx][i];

      if(passed_station[next_station] == -1){
        que.push(next_station);
        passed_station[next_station] = next_cost;
      }
    }

  }
  return -1;
}

int main(){
  ios_base::sync_with_stdio(0);
  cin>>station_num>>linked_num>>hyper_tube_num;
  adj = vector<vector<int>>(station_num + 1 + hyper_tube_num);

  int station;
  for(int hyper_node_idx=station_num+1; hyper_node_idx<= station_num + hyper_tube_num ; ++hyper_node_idx){

    for(int i=0; i<linked_num ; ++i){
      cin>>station;
      adj[hyper_node_idx].push_back(station);
      adj[station].push_back(hyper_node_idx);
    }
  }

  memset(passed_station, -1, sizeof(passed_station));

  int result = HyperBFS();
  if(result == -1)
    cout<<-1<<"\n";
  else
    cout<<(result+1)/2<<'\n';

  return 0;
}
