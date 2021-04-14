//https://www.acmicpc.net/problem/16915
#include<vector>
#include<stack>
#include<algorithm>
#include<iostream>
using namespace std;

int room_num, switch_num;
vector<int> room_state;
vector<vector<int>> connected_switch;
vector<vector<int>> adj;

vector<int> visited_order;
vector<int> scc_label;
stack<int> st;
int order =1, scc_order =1;

int FindSCC(int now_node){
  int min_order = visited_order[now_node] = order++;
  st.push(now_node);

  int next_node;
  for(int i=0; i<adj[now_node].size() ; ++i){
    next_node = adj[now_node][i];
    if(visited_order[next_node] == -1)
      min_order = min(min_order, FindSCC(next_node));
    else if(scc_label[next_node] == -1)
      min_order = min(min_order, visited_order[next_node]);
  }

  if(min_order == visited_order[now_node]){
    int temp;
    while(1){
      temp = st.top();
      st.pop();
      scc_label[temp] = scc_order;
      if(temp == now_node) break;
    }
    ++scc_order;
  }

  return min_order;
}

void TarjanSCC(){
  int node_num = switch_num*2;
  visited_order = vector<int>(node_num, -1);
  scc_label = vector<int>(node_num, -1);
  order = scc_order = 1;

  for(int i=0; i<node_num ; ++i)
    if(visited_order[i] == -1)
      FindSCC(i);
}

bool Solve2SAT(){
  TarjanSCC();

  for(int i=0; i<switch_num*2 ; i+=2){
    if(scc_label[i] == scc_label[i+1])
      return  false;
  }
  return true;
}

int main(){
  ios_base::sync_with_stdio(0);
  cin>>room_num>>switch_num;
  room_state = vector<int>(room_num);
  connected_switch = vector<vector<int>>(room_num);

  for(int i=0; i<room_num ; ++i)
    cin>>room_state[i];

  int connected_num, room_idx;

  for(int i=0; i<switch_num ; ++i){
    cin>>connected_num;
    while(connected_num--){
      cin>>room_idx;
      connected_switch[room_idx-1].push_back(i);
    }
  }

  adj = vector<vector<int>>(switch_num*2);

  int a,b, not_a, not_b;
  for(int i=0; i<room_num ; ++i){   //함의 그래프 생성
    a = connected_switch[i][0]*2;
    b = connected_switch[i][1]*2;
    not_a = a+1; not_b = b+1;

    if(room_state[i] == 0){

      adj[not_a].push_back(b);
      adj[not_b].push_back(a);

      adj[a].push_back(not_b);
      adj[b].push_back(not_a);
    }else{
      adj[a].push_back(b);
      adj[b].push_back(a);

      adj[not_a].push_back(not_b);
      adj[not_b].push_back(not_a);
    }
  }

  cout<<Solve2SAT()<<'\n';

  return 0;
}
