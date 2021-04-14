//https://www.acmicpc.net/problem/3648
#include<stdio.h>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;

int contestant_num, judges_num, node_num;
vector<pair<int,int>> votes;
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
  visited_order = vector<int>(node_num, -1);
  scc_label = vector<int>(node_num, -1);
  order = scc_order = 1;

  for(int i=2; i<node_num ; ++i)
    if(visited_order[i] == -1)
      FindSCC(i);
}

bool Solve2SAT(){
  TarjanSCC();

  if(scc_label[2]>scc_label[3]) //타잔 SCC의 SCC order는 DFS 스패닝 그래프의 역순이므로
    return false;

  for(int i=2; i<node_num ; i+=2){
    if(scc_label[i] == scc_label[i+1])
      return  false;
  }
  return true;
}

int main(){
  while(scanf("%d %d", &contestant_num, &judges_num) != EOF){
    node_num = ((contestant_num*2) + 1)*2;
    adj = vector<vector<int>>(node_num);
    adj[3].push_back(2); //상근이가 반드시 뽑히도록 함의 그래프 간선을 추가

    int a,b, not_a, not_b;
    for(int i=0; i<judges_num ; ++i){
      scanf("%d %d",&a, &b);
      a*=2; not_a = a +1; 
      b*=2; not_b = b +1;

      if(a<0){
        a = -1*(a) +1;
        not_a = a -1;
      }
      
      if(b<0){
        b = -1*(b) +1;
        not_b = b - 1;
      }
      
      adj[not_a].push_back(b);
      adj[not_b].push_back(a);    
  }

    if(Solve2SAT())
      printf("yes\n");
    else
      printf("no\n");
  }

  return 0;
}
