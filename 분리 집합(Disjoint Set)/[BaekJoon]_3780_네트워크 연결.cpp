//https://www.acmicpc.net/problem/3780
#include<vector>
#include<cstdio>
#include<cmath>
using namespace std;

class DisjointSet{
  public:
  vector<int> parent,  line_len;
  DisjointSet(int n) : parent(n+1), line_len(n+1,0) {
    for(int i=0; i<parent.size() ; ++i)
      parent[i]= i;
  }

  int Find(int u){
    if(parent[u] == u)
      return u;
    
    int ret = Find(parent[u]);
    line_len[u] += line_len[parent[u]];
    parent[u] = ret;
    return ret;
  }

  void Union(int u, int v){
    
    parent[u] = v;  //u를 v의 하위 노드로
    line_len[u] = abs(u - v)%1000;
    return;
  }
};

int main(){
  int num, test_num;
  scanf("%d",  &test_num);

  int i,j;
  char k;
  while(test_num--){
  scanf("%d",&num);
  DisjointSet set(num);
    while(1){
      scanf(" %c", &k);
      if(k == 'E'){
        scanf("%d", &i);
        set.Find(i);
        printf("%d\n",set.line_len[i]);
      }else if(k == 'I'){
        scanf("%d %d", &i, &j);
        set.Union(i, j);
      }else{
        break;
      }
    }
  }
  
  return 0;
}
