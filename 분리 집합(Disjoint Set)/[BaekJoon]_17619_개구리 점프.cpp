//https://www.acmicpc.net/problem/17619
#include<vector>
#include<cstdio>
#include<algorithm>
using namespace std;

class DisjointSet{
  public:
  vector<int> parent, rank;
  DisjointSet(int n) : parent(n+1), rank(n+1, 1) { 
    for(int i=0; i<parent.size() ; ++i)
      parent[i] = i;
  }

  int Find(int u){
    if(parent[u] == u)
      return u;

    return parent[u]= Find(parent[u]);
  }

  void Union(int u, int v){
    u = Find(u); v = Find(v);

    if(u==v)
      return;
    
    if(rank[v]< rank[u])
      swap(u,v);
    
    parent[u] = v;
    if(rank[u] == rank[v])
      rank[v]++;

    return;
  }
};

class Log{
  public:
  int left,right, y, num;
  Log() {}
  Log(int x1,int x2, int _y,int n) :left(x1),right(x2), y(_y), num(n){}
};

bool Compare(Log &a, Log& b){
  if(a.right == b.right)
    return a.left< b.left;  //right가 같다면 내림차순
  return a.right > b.right; //right에 대한 오름차순
}

vector<Log> logs;

int main(){
  int log_num,query_num;
  scanf("%d %d", &log_num, &query_num);

  logs = vector<Log>(log_num+1);
  int x1, x2, y;
  for(int idx=1; idx<=log_num ; ++idx){
    scanf("%d %d %d", &x1, &x2, &y);
    logs[idx] = Log(x1,x2 ,y , idx);
  }

  sort(++logs.begin(), logs.end(), Compare);

  DisjointSet set(log_num);
  int next_idx;
  int set_left= logs[1].left;

  for(int idx=1; idx<log_num ; ++idx){
    next_idx = idx +1;
    if(set_left <= logs[next_idx].right)
      set.Union(logs[idx].num, logs[next_idx].num);
    
    set_left = min(set_left,logs[next_idx].left);
  }

  int u, v;
  while(query_num--){
    scanf("%d %d",&u, &v);
    if(set.Find(u) == set.Find(v))
      printf("1\n");
    else
      printf("0\n");
  } 

  return 0;
}
