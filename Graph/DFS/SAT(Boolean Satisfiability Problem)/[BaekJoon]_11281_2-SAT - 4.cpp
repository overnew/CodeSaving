//https://www.acmicpc.net/problem/11281
#include<string.h>
#include<vector>
#include<stack>
#include<algorithm>
#include<iostream>
using namespace std;

int clause_num, variable_num;
vector<pair<int,int>> clauses;
vector<vector<int>> adj;
vector<int> scc_label;

vector<int> visited_order;
stack<int> st;
int order=0, scc_order=0;

int FindSCC(int now_node){
  int min_order = visited_order[now_node] = ++order;
  int next_node;
  st.push(now_node);

  for(int i=0; i<adj[now_node].size() ; ++i){
    next_node = adj[now_node][i];

    if(visited_order[next_node]==-1)
      min_order = min(min_order, FindSCC(next_node));
    else if(scc_label[next_node] == -1) //방문은 했지만 아직 scc에 포함되지 않은 노드
      min_order = min(min_order, visited_order[next_node]);
  }

  if(min_order == visited_order[now_node]){
    int temp;
    while(1){
      temp = st.top();
      st.pop();
      scc_label[temp] = scc_order;
      if(temp == now_node)
        break;
    }
    ++scc_order;
  }

  return min_order;
}

void tarjanSCC(){
  visited_order = vector<int>((variable_num+1)*2+1, -1);
  scc_label = vector<int>((variable_num+1)*2+1, -1);
  order =1;
  scc_order =1;

  for(int i=2; i<visited_order.size(); ++i)
    if(visited_order[i] == -1)
      FindSCC(i);
}

void MakeGraph(){
  adj = vector<vector<int>>((variable_num+1)*2+1);

  int a,b, not_a, not_b;
  for(int i=0; i<clause_num ; ++i){
    a = clauses[i].first;
    b = clauses[i].second;

    if(a<0){
      a = (-a)*2 +1;
      not_a = a -1;
    }else{
      a = a*2;
      not_a = a+1;
    }

    if(b<0){
      b = (-b)*2 +1;
      not_b = b -1;
    }else{
      b = b*2;
      not_b = b+1;
    }

    adj[not_a].push_back(b);
    adj[not_b].push_back(a);
  }
}

vector<int> Solve2SAT(){
  int n = (variable_num+1)*2;
  tarjanSCC();

  for(int i=2; i<=n ; i+=2)
    if(scc_label[i] == scc_label[i+1])
      return vector<int>();

  vector<pair<int,int>> sat_order;
  for(int i=2; i<=n ; ++i)
    sat_order.push_back( make_pair( -scc_label[i], i  ));
  
  sort(sat_order.begin(), sat_order.end());

  vector<int> answer(n/2, -1);
  for(int i=0; i<sat_order.size() ; ++i){
    int vertex = sat_order[i].second;
    int var_idx = vertex/2;
    int is_true = (vertex %2 == 0);
    if(answer[var_idx] != -1)
      continue;
    
    answer[var_idx] = !is_true;
  }
  
  return answer;
}

int main(){
  ios_base::sync_with_stdio(0);
  cin>>variable_num>>clause_num;

  int a,b;
  for(int i=0; i<clause_num ; ++i){
    cin>>a>>b;
    clauses.push_back(make_pair(a, b));
  }

  MakeGraph();

  vector<int> answer = Solve2SAT();

  if(answer.size()==0){
    cout<<0;
  }else{
    cout<<1<<"\n";
    for(int i=1; i<answer.size() ; ++i)
      cout<<answer[i]<<' ';
  }
  cout<<'\n';

  return 0;
}
