//https://www.acmicpc.net/problem/1289
#include <iostream>
#include<vector>
#include<string.h>
using namespace std;

int node_num;
const int MAX_NUM = 100000;
const int MOD = 1000000007;

class Node;
vector<Node> tree;
long long total_weight =0;

class Node{
  public:
  int parent;
  vector<pair<int,int>> children;

  void FindParent(int par, int now){
    parent = par;
    
    for(int i=0; i<children.size() ; ++i){
      if(children[i].first != parent)
        tree[children[i].first].FindParent(now, children[i].first);
    }
  }

  int TreeWeight(int node){
    vector<long long> psum;
    psum.push_back(0);
    
    long long sub_tree_weight;
    for(int i=0; i<children.size() ; ++i){
      if(children[i].first != parent){
        sub_tree_weight = tree[children[i].first].TreeWeight(children[i].first);
        sub_tree_weight = (sub_tree_weight +1) * children[i].second;
        sub_tree_weight %= MOD;
        total_weight += sub_tree_weight;
        psum.push_back( sub_tree_weight );
      }
    }
    total_weight %= MOD;

    for(int i=1; i<psum.size() ; ++i)
      psum[i] = (psum[i]+ psum[i-1]);

    for(int i=2; i<psum.size() ; ++i)
      total_weight += ((psum[i-1] - psum[i-2]) * ((psum[psum.size()-1] - psum[i-1])%MOD)) %MOD;
      
    total_weight %= MOD;

    return psum[psum.size()-1]%MOD;
  }

};

int main(){
  ios_base::sync_with_stdio(0);
  cin>>node_num;

  tree = vector<Node>(node_num+1);

  int u,v,weight;
  for(int i=0; i< node_num-1 ; ++i){
    cin>>u>>v>>weight;
    tree[u].children.push_back(make_pair(v,weight));
    tree[v].children.push_back(make_pair(u,weight));
  }

  tree[1].FindParent(0, 1);
  tree[1].TreeWeight(1);
  cout<<total_weight<<'\n';

  return 0;
}
