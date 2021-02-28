//https://algospot.com/judge/problem/read/EDITORWARS
#include<vector>
#include<iostream>
using namespace std;

int member_num, reply_num;

class DisjointSet{
  public:
  vector<int> parent, rank, set_size, enemy;
  DisjointSet(int n) : parent(n), rank(n,1), set_size(n,1), enemy(n,-1) {
    for(int i=0; i<n ; ++i)
      parent[i] = i;  //초기는 모두 자신이 루트
  }

  int Find(int u){  //u가 속한 트리의 루트 찾기
    if(parent[u] == u)
      return u;
    return parent[u] = Find(parent[u]);
  }

  int Union(int u, int v){
    if(u == -1 || v == -1)
      return max(u,v);

    u = Find(u);
    v = Find(v);

    if(u == v)
      return u;

    if(rank[u] > rank[v]) //항상 v의 rank가 더 크거나 같게
      swap(u, v); 

    parent[u] = v;
    set_size[v] += set_size[u]; 
    if(rank[u] == rank[v]) //같은 경우만 v의 rank가 1 증가
      ++rank[v];

    return v;
  }

  bool Ack(int u, int v){
    u = Find(u);
    v = Find(v);

    if(enemy[u] == v) //서로의 집합이 적인 경우 모순
      return false;
  
    int a = Union(u, v), b = Union(enemy[u],enemy[v]);// 우리의 적들은 서로 동지
    enemy[a] = b;
    if(b != -1) enemy[b] = a;
    return true;
  }

  bool Dis(int u, int v){
    u = Find(u);
    v = Find(v);

    if(u == v)  //같은 집합에 있는 경우 모순
      return false;

    int a = Union(u, enemy[v]), b = Union(v, enemy[u]);
    enemy[a] = b;
    enemy[b] = a;
    return true;
  }

  int FindMaxParty(){
    int max_party_size =0;
    for(int idx=0; idx<set_size.size() ; ++idx){
      if(parent[idx] == idx){
        int enemy_idx = enemy[idx];

        if(enemy_idx > idx)
          continue;
        
        int my_size = set_size[idx];
        int enemy_size = enemy_idx == -1 ? 0 : set_size[enemy_idx];
        max_party_size += max(my_size, enemy_size);
      }
    }
    return max_party_size;
  }

};

int main(){
  ios_base::sync_with_stdio(0);
  int test_num;
  cin>>test_num;

  int a_member, b_member, contradiction_idx;
  string reply;
  while(test_num--){
    cin>>member_num>>reply_num;

    DisjointSet set(member_num);
    bool is_contradiction = false;

    for(int i=1; i<=reply_num ; ++i){
      cin>>reply>>a_member>>b_member;
      
      if(is_contradiction)
        continue;

      if(reply == "ACK"){
        if(!set.Ack(a_member,b_member )){
          contradiction_idx = i;
          is_contradiction = true;
        }
      }else{
        if(!set.Dis(a_member,b_member )){
          contradiction_idx = i;
          is_contradiction = true;
        }
      }
    }

    if(is_contradiction)
      cout<<"CONTRADICTION AT "<<contradiction_idx<<'\n';
    else
      cout<<"MAX PARTY SIZE IS "<<set.FindMaxParty()<<"\n";
  }

  return 0;
}
