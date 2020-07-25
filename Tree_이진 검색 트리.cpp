https://www.acmicpc.net/problem/5639

/*
  이진 트리를 만들고나서 후위 출력함.
  근데 이상하게 계속 제대로 할당이 안됬다. new가 반복문에서 계속 사라져서 그런건지 원..
  
  다른 풀이로는 전위-> 항상 앞값이 root이고 root값보다 작은게 왼쪽 서브 트리, 큰게 오른쪽 서브 트리임을 알면 배열로도 해결이 가능하다.
*/

#include <iostream>
#include<vector>
using namespace std;

class BinaryTree{
  public:
  int value;
  BinaryTree* left;
  BinaryTree* right;

  BinaryTree(int v,BinaryTree* l =nullptr, BinaryTree* r = nullptr){
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
    BinaryTree* node = new BinaryTree(n);
    v.push_back(*node);
    root = node;
  }

  void AddNode(int n){
    BinaryTree* node = new BinaryTree(n);
    v.push_back(*node);
    current = root;

    while(1){
      if(n < current->value){
        if(current->left == nullptr){
          current->left = node;
          break;
        }else
          current = current->left;
      }else{
        if(current->right == nullptr){
          current->right =  node;
          break;
        }else
          current = current->right;
      }
    }
  }

  void PostOrder(BinaryTree* c){
    if(c->left !=nullptr)
      PostOrder(c->left);
    if(c->right !=nullptr)
      PostOrder(c->right);
    cout<<c->value<<'\n';
  }

};


int main() {
  int n;
  cin>>n;
  Tree bin(n);
  ios_base::sync_with_stdio(0);

  while(cin>>n){
    bin.AddNode(n);
  }
  
  bin.PostOrder(bin.root);

  return 0;
}
