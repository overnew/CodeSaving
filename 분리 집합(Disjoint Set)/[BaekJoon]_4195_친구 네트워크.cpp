//https://www.acmicpc.net/problem/4195
#include<vector>
#include<map>
#include<cstdio>
#include<string>
using namespace std;

class DisjointSet{
  public:
  map<string, int> id_map;
  vector<int> parent, set_size, rank;
  DisjointSet(int n) : parent(n+1),set_size(n+1,1), rank(n+1, 1) { 
    for(int i=0; i<parent.size() ; ++i)
      parent[i] = i;
  }

  int Find(int u){
    if(parent[u] == u)
      return u;

    return parent[u]= Find(parent[u]);
  }

  int Union(string u, string v){
    map<string,int>::iterator u_it,v_it;

    u_it = id_map.find(u);
    if(u_it == id_map.end()){
      id_map.insert( make_pair(u,id_map.size()));
      u_it = id_map.find(u);
    }

    v_it = id_map.find(v);
    if(v_it == id_map.end()){
      id_map.insert( make_pair(v,id_map.size()));
      v_it = id_map.find(v);
    }
    int u_idx = u_it->second, v_idx = v_it->second;

    u_idx = Find(u_idx), v_idx = Find(v_idx);
    if(u_idx == v_idx)
      return set_size[v_idx];
    
    if(rank[v_idx]<rank[u_idx])
      swap(u_idx, v_idx);
    
    parent[u_idx] = v_idx;
    set_size[v_idx] += set_size[u_idx];

    if(rank[v_idx] == rank[u_idx])
      rank[v_idx]++;

    return set_size[v_idx];
  }
};

int main(){
  int test_num;
  scanf("%d", &test_num);

  string u, v;
  char u_temp[21], v_temp[21];
  int friend_num;
  while(test_num--){
    scanf("%d",&friend_num);

    DisjointSet set(200000);
    while(friend_num--){
      scanf("%s %s", u_temp,v_temp);
      u = u_temp; v = v_temp;
      printf("%d\n",set.Union(u, v) );
    }
  }

  return 0;
}
