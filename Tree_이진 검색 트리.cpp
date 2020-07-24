https://www.acmicpc.net/problem/5639

#include <iostream>
#include<vector>
using namespace std;

class BinaryTree{
  public:
  int value;
  BinaryTree* left;
  BinaryTree* right;

  BinaryTree(int v,BinaryTree* l =NULL, BinaryTree* r = NULL){
    this->left = l;
    this->right = r;
    this->value =v;
  }
};

class Tree{
  public:
  BinaryTree* root;
  BinaryTree* current;
  BinaryTree* parent;
  vector<BinaryTree> v;

  Tree(int n){
    v.push_back(BinaryTree(n));
    root = &v[0];
  }

  void AddNode(int n){
    v.push_back(BinaryTree(n));
    current = root;

    while(1){
      if(n < current->value){
        if(current->left == NULL){
          current->left = &v.back();
          break;
        }else
          current = current->left;
      }else{
        if(current->right == NULL){
          current->right =  &v.back();
          break;
        }else
          current = current->right;
      }
    }
  }

  void PostOrder(BinaryTree* c){
    if(c->left !=NULL)
      PostOrder(c->left);
    if(c->right !=NULL)
      PostOrder(c->right);
    cout<<c->value<<'\n';
  }

};


int main() {
  int n;
  cin>>n;
  Tree bin(n);
  ios_base::sync_with_stdio(0);

  while(1){
    cin>>n;
    if(n==-1)
      break;
    bin.AddNode(n);
  }

  for(int i=0; i<bin.v.size() ; ++i){
    cout<<bin.v[i].value<<": ";
    if(bin.v[i].left != NULL)
      cout<<bin.v[i].left->value<<", ";
    if(bin.v[i].right != NULL)
      cout<<bin.v[i].right->value;
    cout<<'\n';
  }
  bin.PostOrder(bin.root);

  return 0;
}

#include <iostream>
#include<vector>
using namespace std;

typedef struct bin{
  int value;
  bin* left;
  bin* right;
}binTree;


int main() {
  int temp;
  binTree* binp;
  vector<binTree> v;
  while(true){
    cin>>temp;

    if(temp ==-1)
      break;

    if(v.empty()){
      v.push_back(binTree{temp,NULL,NULL});
    }
    else{
      binp = &v[0];

      while(1){
        if(temp < binp->value){
          if(binp->left != NULL)
            binp = binp->left;
          else{
            v.push_back(binTree{temp,NULL,NULL});
            binp->left = &v[v.size()-1];
            break;
          }

        }else{
          if(binp->right != NULL)
              binp = binp->right;
          else{
            v.push_back(binTree{temp,NULL,NULL});
            binp->right = &v[v.size()-1];
            break;
          }

          
        }


      }

    }
  }

  for(int i=0; i<v.size() ; ++i){
    cout<<v[i].value<<endl;
  }

  binp = &v[0];
  while(binp->left != NULL){
    cout<<binp->value<<endl;
    binp = binp->left;
  }

  


  return 0;
}
