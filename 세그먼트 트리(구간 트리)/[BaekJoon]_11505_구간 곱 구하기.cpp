https://www.acmicpc.net/problem/11505
#include<vector>
#include<cstdio>
#include<cmath>
using namespace std;

typedef long long ll;

const int MOD = 1000000007;
int N, M, K;
vector<ll> arr;
vector<ll> segment_tree;

ll Init(int left, int right , int node){
  if(left == right)
    return segment_tree[node] = arr[left];
  
  int mid = (left+right)/2;
  segment_tree[node] = ( Init(left,mid, node*2) * Init( mid+1, right, node*2 +1))%MOD;
  return segment_tree[node];
}

ll Update(int left, int right , int node, int idx, ll num){
  if(right < idx || idx < left )
    return segment_tree[node];  //변화 x의 값을 반환
  
  if(left == right){  //== idx인 경우
    return segment_tree[node] = num;
  }

  int mid = (left+right)/2;
  segment_tree[node] = (Update(left,mid, node*2,idx ,num ) * Update(mid+1, right, node*2 +1,idx ,num ))%MOD;
  return segment_tree[node];
}

ll Query(int left, int right, int query_left ,int query_right , int node){
  
  if( right < query_left || query_right < left)
    return 1;
  
  if(query_left <= left  && right <= query_right )
    return segment_tree[node];
  //else

  int mid = (left+right)/2;
  return (Query(left, mid, query_left, query_right ,node*2) *Query(mid+1, right, query_left, query_right ,node*2+1) )%MOD ;
}

int main(){
  scanf("%d %d %d", &N, &M, &K);
  arr = vector<ll>(N+1);
  int tree_height = (int)ceil(log2(N));
  segment_tree = vector<ll>(1<<(tree_height+1));

  int num;
  for(int i=1; i<=N ; ++i){
    scanf("%d", &num);
    arr[i] = num;
  }

  Init(1, N, 1);

  M += K;
  int a,b;
  while(M--){
    scanf("%d", &a);
    if(a == 1){
      ll c;
      scanf("%d %lld",&b,&c);
      Update(1, N, 1, b, c);
    }else{
      int c;
      scanf("%d  %d",&b,&c);
      printf("%lld\n", Query(1, N, b, c, 1));
    }
  }

  return 0;
}
