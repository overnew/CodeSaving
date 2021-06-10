//https://www.acmicpc.net/problem/9577
#include<iostream>
#include<queue>
using namespace std;

int part_num, seed_num;
vector<int> time_match, part_match, visited;
vector<vector<bool>> adj;

bool DFS(int time){
  if(visited[time])
    return false;
  visited[time] = true;

  for(int part=1; part<=part_num ; ++part)
    if(adj[time][part])
      if(part_match[part] == -1 || DFS(part_match[part])){
        time_match[time] = part;
        part_match[part] = time;
        return true;
      }
  
  return false;
}

int main(){
  ios_base::sync_with_stdio(0);
  int test_num;
  cin>>test_num;

  while(test_num--){
    cin>>part_num>>seed_num;
    adj = vector<vector<bool>>(101, vector<bool>(part_num+1, false));

    int last_time = 0;
    int start_time, end_time, have_parts, part_idx;
    for(int i=0; i<seed_num ; ++i){
      cin>>start_time>>end_time>>have_parts;
      last_time = max(last_time, end_time);

      for(int j=0; j<have_parts ; ++j){
        cin>>part_idx;
        for(int time=start_time; time<end_time ; ++time)
          adj[time][part_idx] = true;
      }
    }

    time_match = vector<int>(last_time, -1);
    part_match = vector<int>(part_num+1, -1);

    int download_size = 0, finished_time = -1;
    for(int start =0; start<last_time ; ++start){
      visited = vector<int>(last_time, false);

      if(DFS(start))
        ++download_size;
      
      if(download_size == part_num){
        finished_time = start+1;
        break;
      }
    }
    cout<<finished_time<<'\n';
  }

  return 0;
}
