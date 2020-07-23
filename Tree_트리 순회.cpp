//https://www.acmicpc.net/problem/1991
//2020.07.23 23:07에 트리 문제를 시작한다! 트리문제의 어려운 점은 상황에 맞게 알맞은 트리를 생성할 줄 알아야 되는 것이기 때문인가 

#include <iostream>
using namespace std;

char arr[26][2];

void preorder(int idx){
  char temp = 'A' + idx;
  cout<<temp;
  if(arr[idx][0] != '.')
    preorder(arr[idx][0] - 'A');
  
  if(arr[idx][1] != '.')
    preorder(arr[idx][1] - 'A');
}

void inorder(int idx){
  char temp = 'A' + idx;
  if(arr[idx][0] != '.')
    inorder(arr[idx][0] - 'A');
  cout<<temp;
  if(arr[idx][1] != '.')
    inorder(arr[idx][1] - 'A');
}


void postorder(int idx){
  char temp = 'A' + idx;
  if(arr[idx][0] != '.')
    postorder(arr[idx][0] - 'A');
  if(arr[idx][1] != '.')
    postorder(arr[idx][1] - 'A');
  cout<<temp;
}


int main() {
  int n;
  char la;
  cin>>n;

  for(int i=0; i<n ; ++i){
    cin>>la;
    cin>>arr[la-'A'][0]>>arr[la-'A'][1];
  }

  preorder(0);
  cout<<'\n';
  inorder(0);
  cout<<'\n';
  postorder(0);
  cout<<'\n';
  
  return 0;
}
