//https://www.acmicpc.net/problem/1693
#include <iostream>
#include<vector>
#include<string.h>
using namespace std;

int node_num;
const int max_color = 19;
int dp[100001][max_color];

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

  int FindMinCost(int node, int now_color){
    int& ret = dp[node][now_color];
    if(ret != -1)
      return  ret;
    
    int min_result=0;
    ret = now_color;  //자신은 now_color로 칠해지므로 미리 cost를 추가

    for(int i=0; i<children.size() ; ++i){
      if(children[i] != parent){
        min_result = 1000000;

        for(int color=1; color<=max_color ; ++color){
          if(color != now_color){
            min_result = min(min_result, tree[children[i]].FindMinCost(children[i], color) );

          }
        }
        ret += min_result;
      }

    }

    return ret;
  }

};

int main(){
  ios_base::sync_with_stdio(0);
  cin>>node_num;

  tree = vector<Node>(node_num+1);

  int u,v;
  tree[0].children.push_back(1);  //계산의 편의를 위해 1의 부모 노드인 0노드를 추가
  tree[1].children.push_back(0);

  for(int i=0; i<node_num-1 ; ++i){
    cin>>u>>v;
    tree[u].children.push_back(v);
    tree[v].children.push_back(u);
  }

  tree[0].FindParentDFS(0, 0);    //0을 루트로 한 트리에서 각 노드의 부모를 찾아줌
  
  memset(dp, -1, sizeof(dp));
  cout<<tree[0].FindMinCost(0, 0)<<'\n'; 

  return 0;
}
