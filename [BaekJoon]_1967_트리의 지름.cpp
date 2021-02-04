//https://www.acmicpc.net/problem/1967
#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

int node_num;

class Node{
  public:
  vector<pair<Node*, int>> children;

  void AddChild(Node* child, int cost){
    children.push_back(make_pair(child, cost));
  }
};

vector<Node> tree;
int longest =0;

int FindTreeRadius(Node* root){
  if(root->children.size() ==0)
    return 0;
  
  vector<int> costs;
  
  for(int i=0; i<root->children.size() ; ++i)
    costs.push_back(FindTreeRadius(root->children[i].first) + root->children[i].second);

  if(costs.size()>1){
    sort(costs.begin(),costs.end(),greater<>());
    longest = max(longest, costs[0]+costs[1]);
  }
  
  return costs[0];
}

int main(){
  ios_base::sync_with_stdio(0);
  cin>>node_num;

  tree = vector<Node>(node_num+1);

  int parent, child, cost;
  for(int i=0; i<node_num-1 ; ++i){
    cin>>parent>>child>>cost;
    tree[parent].AddChild(&tree[child], cost);
  }

  int result = FindTreeRadius(&tree[1]);
  cout<<max(result, longest)<<"\n";

  return 0;
}
