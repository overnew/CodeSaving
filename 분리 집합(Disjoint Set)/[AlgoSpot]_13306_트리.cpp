//https://www.acmicpc.net/problem/13306
#include<vector>
#include<cstdio>
using namespace std;

class DisjointSet{
  public:
  vector<int> parent;
  DisjointSet(int n) : parent(n+1) { 
    for(int i=0; i<parent.size() ; ++i)
      parent[i] = i;
  }

  int Find(int u){
    if(parent[u] == u)
      return u;
    return parent[u] = Find(parent[u]);
  }
};

int main(){
  int vertax_num, type2_num;
  scanf("%d %d", &vertax_num, &type2_num);

  vector<int> parent_arr(vertax_num+1);
  int parent_idx;
  parent_arr[1] = 1;
  for(int i=2; i<=vertax_num ; ++i){
    scanf("%d", &parent_idx);
    parent_arr[i] = parent_idx;
  }

  int query_num =type2_num + vertax_num-1;
  vector<pair<int,int>> queries(query_num);

  int x, vertax_idx1, vertax_idx2, cnt =0;
  for(int i =0 ; i<query_num ; ++i){
    scanf("%d", &x);
    if(x == 0){
      scanf("%d", &vertax_idx1);
      queries[cnt++] =  make_pair(0, vertax_idx1) ;  //first가 0이면 (1)의 형태
    }else{
      scanf("%d %d", &vertax_idx1, &vertax_idx2);
      queries[cnt++] = make_pair(vertax_idx1, vertax_idx2);//(2)형태는 first=vertax_idx1, second= vertax_idx2
    }
  }

  vector<bool> type2_answer(type2_num);
  DisjointSet set(vertax_num);
  cnt =0;
  for(int i =query_num-1 ; i>=0 ; --i){
    if(queries[i].first == 0)
      set.parent[queries[i].second] = parent_arr[queries[i].second];
    else
      type2_answer[cnt++] = set.Find(queries[i].first) == set.Find(queries[i].second);
  }

  for(int i = type2_num-1 ; i>=0 ; --i){
    if(type2_answer[i])
      printf("YES\n");
    else
      printf("NO\n");
  }

  return 0;
}
