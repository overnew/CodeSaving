//https://www.acmicpc.net/problem/2533
#include <iostream>
#include<vector>
#include<string.h>
using namespace std;

int node_num;
int dp[1000001][2];

class Node; // 클래스 선언부
vector<Node> tree;

class Node{ //클래스 정의부
  public:
  int parent;
  vector<int> children;

  void FindParentDFS(int par, int now){
    parent = par;

    for(int i=0; i<children.size() ; ++i)
      if(children[i] != parent)
        tree[children[i]].FindParentDFS(now,children[i]);
      
  }

  int MinEarlyAdaptor(int node, int is_adaptor){
  
    int& ret = dp[node][is_adaptor];
    if(ret != -1)
      return ret;
  
    int min_result=0;

    ret =0;
    for(int i=0; i<children.size() ; ++i){
      if(children[i] != parent){
        min_result = tree[children[i]].MinEarlyAdaptor(children[i], 1);

        if(is_adaptor)  //node가 어뎁터인 경우
          min_result = min(min_result, tree[children[i]].MinEarlyAdaptor(children[i], 0));
        
        ret += min_result;
      }
    }

    if(is_adaptor)  //자기 자신이 어뎁터인 경우 +1
      ++ret;

    return ret;
  }

};


int main(){
  ios_base::sync_with_stdio(0);
  cin>>node_num;

  tree = vector<Node>(node_num+1);

  int u,v;
  for(int i=0; i<node_num-1 ; ++i){
    cin>>u>>v;
    tree[u].children.push_back(v);
    tree[v].children.push_back(u);
  }

  tree[1].FindParentDFS(0, 1);    //1을 루트로 한 트리에서 각 노드의 부모를 찾아줌
  
  memset(dp, -1, sizeof(dp));
  
  tree[1].MinEarlyAdaptor(1, 0);  //루트가 어뎁터가 아닌 경우 최소값
  tree[1].MinEarlyAdaptor(1, 1);  //루트가 어뎁터인 경우 최솟값

  cout<<min(dp[1][0], dp[1][1])<<'\n';

  return 0;
}
