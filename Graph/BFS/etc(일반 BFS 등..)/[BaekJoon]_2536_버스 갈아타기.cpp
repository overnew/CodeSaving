//https://www.acmicpc.net/problem/2536
#include<vector>
#include<iostream>
#include<queue>
using namespace std;

struct BusInfo{
  int idx;
  bool is_horizon;
  pair<int,int> start_pos, end_pos;
};

int row, column, bus_num;
int start_r, start_c, dest_r, dest_c;
BusInfo buses[5001];
vector<vector<int>> adj;

int BFS(){
  vector<int> visited(bus_num+1, -1);
  vector<bool> is_dest(bus_num+1, false);
  queue<int> que;

  for(int i =1; i<=bus_num ; ++i){  //시작점을 지나는 라인을 큐 넣어두기
    if(buses[i].is_horizon){  //수평인 경우
      if(buses[i].start_pos.first != start_r || buses[i].start_pos.second > start_c || start_c > buses[i].end_pos.second)
        continue;
    }else{
      if(buses[i].start_pos.second != start_c || buses[i].start_pos.first > start_r || start_r > buses[i].end_pos.first)
        continue;
    }
    que.push(buses[i].idx);
    visited[buses[i].idx] = 1;
  }

  for(int i =1; i<=bus_num ; ++i){  //도착점을 지나는 라인은 표시해주자
    if(buses[i].is_horizon){  //수평인 경우
      if(buses[i].start_pos.first == dest_r && buses[i].start_pos.second <=dest_c &&dest_c<= buses[i].end_pos.second)
        is_dest[buses[i].idx] = true;
    }else{
      if(buses[i].start_pos.second ==dest_c && buses[i].start_pos.first <= dest_r && dest_r<= buses[i].end_pos.first)
        is_dest[buses[i].idx] = true;
    }
  }

  int bus_idx,transfer_num , min_transfer;
  while(!que.empty()){
    bus_idx = que.front();
    que.pop();
    transfer_num = visited[bus_idx];

    if(is_dest[bus_idx]){
      min_transfer = transfer_num;
      break;
    }

    int next_bus;
    for(int i=0; i<adj[bus_idx].size() ; ++i){
      next_bus = adj[bus_idx][i];
      if(visited[next_bus] == -1){
        que.push(next_bus);
        visited[next_bus] = transfer_num +1;
      }
    }
  }

  return min_transfer;
}

int main(){
  ios_base::sync_with_stdio(0);
  cin>>row>>column>>bus_num;
  adj = vector<vector<int>>(bus_num+1);

  int bus_idx, r1, r2, c1, c2;
  for(int i=1; i<=bus_num ; ++i){
    cin>>bus_idx>>c1>>r1>>c2>>r2;
    buses[i].idx = bus_idx;

    if(r1 == r2)
      buses[i].is_horizon = true;
    else
      buses[i].is_horizon = false;

    if(r1> r2 || c1 > c2){
      buses[i].start_pos = make_pair(r2, c2); 
      buses[i].end_pos = make_pair(r1, c1);
    }else{
      buses[i].start_pos = make_pair(r1, c1); 
      buses[i].end_pos = make_pair(r2, c2);
    }


    BusInfo& now_bus = buses[i], comp_bus;
    for(int j=1; j<i ; ++j){
      comp_bus = buses[j];
      
      if(comp_bus.is_horizon == now_bus.is_horizon){ //같은 방향
        if(now_bus.is_horizon){ //지금 버스 라인이 수평인 경우
          if( now_bus.start_pos.first != comp_bus.start_pos.first || comp_bus.end_pos.second < now_bus.start_pos.second || now_bus.end_pos.second < comp_bus.start_pos.second  )
            continue;
        }else{
          if( now_bus.start_pos.second != comp_bus.start_pos.second ||comp_bus.end_pos.first < now_bus.start_pos.first || now_bus.end_pos.first < comp_bus.start_pos.first  )
            continue;
        }

      }else{  //다른 방향
        if(now_bus.is_horizon){ //지금 버스 라인이 수평인 경우
          if((now_bus.start_pos.first < comp_bus.start_pos.first || comp_bus.end_pos.first < now_bus.start_pos.first) || (comp_bus.start_pos.second < now_bus.start_pos.second ||  now_bus.end_pos.second < comp_bus.start_pos.second))
            continue;
        }else{
          if((comp_bus.start_pos.first < now_bus.start_pos.first || now_bus.end_pos.first < comp_bus.start_pos.first) || (now_bus.start_pos.second < comp_bus.start_pos.second ||  comp_bus.end_pos.second < now_bus.start_pos.second))
            continue;
        }
      }

      adj[now_bus.idx].push_back(comp_bus.idx);
      adj[comp_bus.idx].push_back(now_bus.idx);
    }

  }

  cin>>start_c>>start_r>>dest_c>>dest_r;

  cout<<BFS()<<"\n";

  return 0;
}
