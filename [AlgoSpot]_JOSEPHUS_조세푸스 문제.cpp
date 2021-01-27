//https://algospot.com/judge/problem/read/JOSEPHUS
#include <iostream>
using namespace std;

int N,K;

class Node{
  public:
  int number;
  Node* prev_node;
  Node* next_node;

  Node(int n): number(n){}

  void DeleteSelf(){
    prev_node->next_node = next_node;
    next_node->prev_node = prev_node;
    --N;
    delete this;
  }
};

int main(){
  int test_num;
  cin>>test_num;

  while(test_num--){
    cin>>N>>K;

    Node* first_node =new Node(1);
    Node* prev = first_node;
    Node* now;
    for(int i=2; i<=N ; ++i){
      now = new Node(i);
      now->prev_node =prev;
      prev->next_node = now;
      prev = now;
    }
    now->next_node = first_node;
    first_node->prev_node = now;

    now = first_node;
    Node* to_kill;
    int order=0;
    while(N >2){
      if(order ==0){
        to_kill =now;
        now = now->next_node;
        to_kill->DeleteSelf();
        order = K-1;
      }else{
        --order;
        now = now->next_node;
      }
    }

    int fr = now->number;
    int se = now->next_node->number;

    if(fr<se)
      cout<<fr<<" "<<se<<'\n';
    else
      cout<<se<<" "<<fr<<'\n';
    
  }
  return 0;
}
