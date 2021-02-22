//https://www.acmicpc.net/problem/7578
#include<vector>
#include<cstdio>
#include<cmath>
using namespace std;

typedef long long ll;

int machine_num;
int serial_number[500001];
int b_line_idx[1000001];

vector<ll> segment_tree;

void Update(int left, int right, int node, int idx, ll num){
  if( right < idx || idx < left)
    return;

  segment_tree[node] += num;
  int mid = (left + right)/2;
  if(left != right){
    Update(left, mid, node*2, idx, num);
    Update(mid+1, right, node*2+1, idx, num);
  }
}

ll Sum(int left, int right,int query_left, int query_right ,int node){
  if( right < query_left || query_right < left )
    return 0;
  
  if( query_left <= left && right <= query_right)
    return segment_tree[node];
  
  int mid = (left + right)/2;
  return Sum(left, mid, query_left, query_right, node*2) + Sum(mid+1, right, query_left, query_right, node*2+1);
}

int main(){
  scanf("%d", &machine_num);
  int tree_height = (int)ceil(log2(machine_num));
  segment_tree = vector<ll>(1<<(tree_height + 1) , 0); //모두 0으로 초기화

  for(int idx=1; idx<=machine_num ; ++idx){
    scanf("%d", &serial_number[idx]);
  }

  int num;
  for(int idx=1; idx<=machine_num ; ++idx){
    scanf("%d", &num);
    b_line_idx[num] = idx;
  }

  ll result =0;
  for(int idx=1; idx<=machine_num ; ++idx){
    int b_idx = b_line_idx[serial_number[idx]];
    result += Sum(1, machine_num, b_idx+1, machine_num , 1);
    Update(1,machine_num ,1 ,b_idx , 1);
  }

  printf("%lld\n",result);
  return 0;
}
