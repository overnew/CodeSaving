//https://www.acmicpc.net/problem/3977
#include<stdio.h>
#include<string.h>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;

const int MAXN = 100001;

int area_num, movement_num;
vector<vector<int>> adj;
vector<int> visited_order;
stack<int> st;
vector<vector<int>> scc_set;
int scc_number[MAXN];
int indegree[MAXN];
int order, scc_cnt;

int FindSCC(int now_area){
  int next_area;
  int min_order = visited_order[now_area] = order++;
  st.push(now_area);

  for(int i=0; i < adj[now_area].size() ; ++i){
    next_area = adj[now_area][i];
    if(visited_order[next_area] == -1)
      min_order = min(min_order, FindSCC(next_area));
    else if(scc_number[next_area] == -1)
      min_order = min(min_order, visited_order[next_area]);
    else
      indegree[scc_number[next_area]]++;  //이미 scc를 이룬 노드에 접근시 해당 scc로의 진입 차수가 증가
  }

  if(min_order == visited_order[now_area]){
    int temp;
    vector<int> new_scc;

    while(1){
      temp = st.top();
      st.pop();
      scc_number[temp] = scc_cnt;
      new_scc.push_back(temp);
      
      if(temp == now_area)
        break;
    }

    if(!st.empty()) //stack이 비지 않았다면 상위 노드에서 새로 구성된 SCC로의 진입이 있었다는 뜻
      indegree[scc_cnt]++;

    scc_cnt++;
    scc_set.push_back(new_scc);
  }

  return min_order;
}

int main(){
  int test_num;
  scanf("%d",&test_num);

  while(test_num--){
    scanf("%d %d",&area_num, &movement_num);
    adj = vector<vector<int>>(area_num);
    visited_order = vector<int>(area_num, -1);
    scc_set.clear();

    int a,b;
    for(int i=0; i<movement_num ; ++i){
      scanf("%d %d", &a, &b);
      adj[a].push_back(b);
    }

    order = scc_cnt = 0;  //순서 초기화
    memset(scc_number, -1, sizeof(scc_number));
    memset(indegree, 0, sizeof(indegree));
    
    for(int i=0; i<area_num ; ++i)
      if(visited_order[i] == -1)
        FindSCC(i);

    int cnt_indegree_zero =0, answer_number;
    for(int i=0; i<scc_cnt ; ++i){
      if(indegree[i] == 0){
        answer_number = i;
        cnt_indegree_zero++; 
      }
    }

    if(cnt_indegree_zero==1){ //진입차수 indegree가 0인 scc가 1개인 경우
      sort(scc_set[answer_number].begin(), scc_set[answer_number].end());
      for(int i=0; i<scc_set[answer_number].size() ; ++i)
        printf("%d\n", scc_set[answer_number][i]);
    }else{
      printf("Confused\n");
    }

    printf("\n");
  }

  return 0;
}
