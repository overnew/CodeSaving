//https://www.acmicpc.net/problem/11437
#include <iostream>
#include<vector>
using namespace std;

class Node{
  public:
  int num, height;
  Node* parent;
  vector<Node*> links;

  void AddLinks(Node* link){
    links.push_back(link);
  }

  void SetParentAndHeight(Node* par, int h){
    parent = par;
    height = h;

    for(int i=0; i<links.size() ; ++i){
      if(links[i] != par)
        links[i]->SetParentAndHeight(this, h+1);
    }
  }

};

int node_num;
vector<Node> tree;

Node* FindLCA(Node* a, Node* b){
  Node* p1 = a;  
  Node* p2 = b;

  if(a->height != b->height){   //높이가 다르면 같아지게 만듬
    if(a->height < b->height){  //p1은 더 높이가 큰 경우
      p1 = b;
      p2 = a;
    }

    while(p1->height != p2->height)
      p1 = p1->parent;
  } 

  while(p1 != p2){
    p1 = p1->parent;
    p2 = p2->parent;
  }

  return p1;
}

int main(){
  ios_base::sync_with_stdio(0);
  cin>>node_num;

  tree = vector<Node>(node_num+1);
  for(int i=1; i<=node_num ; ++i)
    tree[i].num= i;

  int a,b;
  for(int i=0 ; i<node_num-1 ; ++i ){
    cin>>a>>b;
    tree[a].AddLinks(&tree[b]);
    tree[b].AddLinks(&tree[a]);
  }
  tree[1].SetParentAndHeight(nullptr, 0);

  int pair_num;
  cin>>pair_num;
  while(pair_num--){
    cin>>a>>b;
    cout<<FindLCA(&tree[a], &tree[b])->num<<'\n';
  }

  return 0;
}
