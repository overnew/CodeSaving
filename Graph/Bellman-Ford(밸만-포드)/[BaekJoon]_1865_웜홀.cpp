//https://www.acmicpc.net/problem/1865
#include<iostream>
#include<vector>
using namespace std;

const int INF = 51000000;
int vertex_num, road_num, wormhole_num;
vector<vector<pair<int,int>>> adj;

bool BellmanFord(int start_idx){
  vector<int> upper(vertex_num+1, INF);
  bool is_updated = false;
  upper[start_idx] = 0;

  int next_idx, cost;
  for(int iter=0 ; iter<vertex_num ; ++iter){
    is_updated = false;

    for(int idx = 1; idx<=vertex_num ; ++idx){
      for(int i=0; i<adj[idx].size() ; ++i){
        next_idx = adj[idx][i].first;
        cost = adj[idx][i].second;


        if(cost + upper[idx] < upper[next_idx]){
          upper[next_idx] = cost + upper[idx];
          is_updated = true;
        }
      }
    }

    if(!is_updated) //더이상 완화가 안 된다면 진행할 의미가 없다. 
      break;
  }

  if(is_updated)  //vertex_num번째에서도 완화가 일어나면 음수 사이클이 있다는 의미
    return true;
  return false;
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  int test_num;
  cin>>test_num;

  while(test_num--){
    cin>>vertex_num>>road_num>>wormhole_num;
    adj = vector<vector<pair<int,int>>>(vertex_num+1);

    int s, e, t;
    for(int i =0; i<road_num; ++i){ //도로는 양방향
      cin>>s>>e>>t;
      adj[s].push_back({e,t});
      adj[e].push_back({s,t});
    }

    for(int i =0; i< wormhole_num ; ++i){ //웜홀은 단방향
      cin>>s>>e>>t;
      adj[s].push_back({e,-t});
    }

    bool is_pos = BellmanFord(1);
    if(is_pos)
      cout<<"YES\n";
    else 
      cout<<"NO\n";

  }
  return 0;
}
