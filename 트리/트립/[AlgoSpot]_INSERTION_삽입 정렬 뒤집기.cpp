//https://algospot.com/judge/problem/read/INSERTION
#include <iostream>
using namespace std;

typedef int KeyType;

struct Node{
  KeyType key;
  int priority, size; //우선순위는 난수로 결정
  Node *right=NULL, *left=NULL;
  Node(const KeyType& _key): key(_key), priority(rand()), size(1) {}

  void SetLeft(Node* newLeft) { left = newLeft; CalcSize();}
  void SetRight(Node* newRight) {right = newRight; CalcSize();}

  void CalcSize(){
    size = 1;
    if(left) size += left->size;
    if(right) size += right->size;
  }
};

typedef pair<Node*, Node*> NodePair;  

NodePair split(Node* root, KeyType key){  //first: key보다 작은 서브 트리, second: key보다 큰 서브 트리
  if(root == NULL) return NodePair(NULL, NULL);

  if(root->key < key){
    NodePair r_sub = split(root->right,key);
    root->SetRight(r_sub.first);
    return NodePair(root, r_sub.second);
  }
  //else
  NodePair l_sub = split(root->left, key);
  root->SetLeft(l_sub.second);
  return  NodePair(l_sub.first,root);
}

Node* Insert(Node* root, Node* node){
  if(root == NULL)
    return node;

  if(root->priority < node->priority){
    NodePair splitted = split(root, node->key);
    node->SetLeft(splitted.first);
    node->SetRight(splitted.second);
    return node;
  }else if(root->key > node->key){
    root->SetLeft(Insert(root->left, node));
  }else{
    root->SetRight(Insert(root->right, node));
  }
  return root;
}

Node* Merge(Node* a,Node* b){ // a서브 트리는 항상 b의 서브트리의 모든 노드보다 작다
  if(a==NULL) return b;
  if(b==NULL) return a;
  if(a->priority < b->priority){
    b->SetLeft(Merge(a, b->left));
    return b;
  }
  //else
  a->SetRight(Merge(a->right, b));
  return a;
}

Node* Erase(Node* root, KeyType key ){
  if(root == NULL) return root;

  if(root->key == key){
    Node* ret = Merge(root->left, root->right);
    delete root;
    return ret;
  }else if(key <root->key )
    root->SetLeft(Erase(root->left, key));
  else 
    root->SetRight(Erase(root->right,key));
  
  return  root;
}

Node* KthNode(Node* root, int k){
  int left_size = 0;
  if(root->left != NULL) left_size= root->left->size;
  if(k<=left_size) return KthNode(root->left,k);
  if(k == left_size + 1) return root;
  return KthNode(root->right, k - left_size -1);
}

int CountLessThan(Node* root, KeyType key){
  if(root == NULL) return 0;
  if(root->key >= key)
    return CountLessThan(root->left, key);
  int left_size = root->left ? root->left->size : 0;
  return left_size + 1 + CountLessThan(root->right, key);
}

int main(){
  ios_base::sync_with_stdio(0);
  int test_num, arr_size;
  int arr[50000];
  int answer[50000];
  cin>>test_num;

  while(test_num--){
    cin>>arr_size;
    for(int i=0; i<arr_size ; ++i)
      cin>>arr[i];
    
    Node* root = NULL;

    for(int i=1; i<=arr_size ; ++i){
      root = Insert(root, new Node(i));
    }

    for(int i=arr_size-1; i>=0 ; --i){
      Node* k = KthNode(root, i + 1 - arr[i]);
      answer[i] = k->key;
      root = Erase(root, k->key);
    }

    for(int i=0; i<arr_size; ++i)
      cout<<answer[i]<<' ';
    
    cout<<'\n';
  }

  return 0;
}
