//https://www.acmicpc.net/problem/1717
#include<vector>
#include<cstdio>
using namespace std;

class DisjointSet{
  public:
  vector<int> parent, rank;
  DisjointSet(int n) : parent(n+1), rank(n+1,1) {
    for(int i=0; i<parent.size() ; ++i)
      parent[i]= i;
  }

  int Find(int u){
    if(parent[u] == u)
      return u;
    return parent[u] = Find(parent[u]);
  }

  void Union(int u, int v){
    u = Find(u); v = Find(v);

    if(u == v)
      return;
    
    if(rank[v] < rank[u]) //rank는 항상 v가 크도록
      swap(u,v);

    parent[u] = v;  //u를 v의 하위 노드로
    if(rank[v] == rank[u])
      ++rank[v];
    
    return;
  }
};

int main(){
  int num, operation_num;
  scanf("%d %d", &num, &operation_num);

  int k,a,b;
  DisjointSet set(num);
  while(operation_num--){
  scanf("%d %d %d", &k, &a, &b);

    if(k==0){
      set.Union(a, b);
    }else{
      if(set.Find(a) == set.Find(b))
        printf("YES\n");
      else
        printf("NO\n");
    }
  }
  
  return 0;
}
