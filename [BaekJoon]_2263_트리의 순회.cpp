//https://www.acmicpc.net/problem/2263
#include <iostream>
using namespace std;

int node_num;
int inorder[100000];
int postorder[100000];

void PrintPreOrder(int in_l,int in_r,  int post_l, int post_r){
  if(in_l>in_r || post_l>post_r)
    return;

  int root = postorder[post_r];
  int in_root;
  cout<< root <<' ';

  if(post_r == post_l)
    return;

  for(int i=in_l; i<=in_r ; ++i)
    if(inorder[i] == root){
      in_root = i;
      break;
    }

  int left_size = in_root - in_l;
  PrintPreOrder(in_l,in_root-1 ,post_l , post_l+ left_size -1);  //왼쪽 부분
  PrintPreOrder(in_root+1,in_r , post_l+ left_size, post_r-1 );  //오른쪽 부분
  return;
}


int main(){
  ios_base::sync_with_stdio(0);
  cin>>node_num;

  for(int i=0; i<node_num ; ++i)
    cin>>inorder[i];
  
  for(int i=0; i<node_num ; ++i)
    cin>>postorder[i];

  PrintPreOrder(0, node_num-1, 0, node_num-1);
  cout<<'\n';

  return 0;
}
