//https://www.acmicpc.net/problem/1395
#include<vector>
#include<cmath>
#include<cstdio>
using namespace std;

vector<int> segment_tree;
vector<int> lazy; //해당 구간의 스위치가 눌린횟수

void UpdateLazy(int left, int right, int node){
  if(lazy[node] %2 == 1){ //홀수일때만 의미가 있다.
    segment_tree[node] = (right - left +1) - segment_tree[node];
    if(left != right){
      lazy[node*2] += lazy[node];
      lazy[node*2 + 1] += lazy[node];
    }
    lazy[node] = 0;
  }
}

void UpdateRange(int left, int right, int range_left, int range_right, int node){
  UpdateLazy(left, right,node);
  if(range_right < left || right < range_left)
    return;
  
  if(range_left <= left && right<= range_right){
    segment_tree[node] = (right - left +1) - segment_tree[node];
    if(left != right){
      lazy[node*2] += 1;
      lazy[node*2 + 1] += 1;
    }
    return;
  }

  int mid = (left + right)/2;
  UpdateRange(left, mid , range_left ,range_right  , node*2 );
  UpdateRange(mid+1, right , range_left ,range_right  , node*2+1 );

  segment_tree[node] = segment_tree[node*2] + segment_tree[node*2+1];
  return;
}

int SumOnSwitch(int left, int right, int range_left, int range_right, int node){
  UpdateLazy(left, right,node);
  if(range_right < left || right < range_left)
    return 0;

  if(range_left <= left && right<= range_right)
    return segment_tree[node];

  int mid = (left + right)/2;
  return SumOnSwitch(left, mid , range_left ,range_right  , node*2) + SumOnSwitch(mid+1, right , range_left ,range_right  ,node*2+1);
}

int main(){
  int switch_num,M;
  scanf("%d %d", &switch_num, &M);

  int tree_height = (int)ceil(log2(switch_num));
  segment_tree = vector<int>(1<<(tree_height+1));
  lazy = vector<int>(1<<(tree_height+1));

  int O,S,T;
  while(M--){
    scanf("%d %d %d", &O, &S, &T);
    if(O == 0)
      UpdateRange(1, switch_num, S,T ,1 );
    else
      printf("%d\n", SumOnSwitch(1, switch_num, S,T ,1 ));
  }

  return 0;
}
