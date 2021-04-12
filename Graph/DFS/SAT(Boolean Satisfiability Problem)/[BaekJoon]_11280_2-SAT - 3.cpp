//https://www.acmicpc.net/problem/11280
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

bool Solve2SAT(){
  int n = (variable_num+1)*2;
  tarjanSCC();

  for(int i=2; i<=n ; i+=2)
    if(scc_label[i] == scc_label[i+1])
      return false;
  
  return true;
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

  cout<<Solve2SAT()<<"\n";
  return 0;
}
