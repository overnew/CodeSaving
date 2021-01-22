//https://www.acmicpc.net/problem/2042
#include <iostream>
#include<vector>
#include<cmath>
using namespace std;
typedef long long ll;

int N,M,K;

vector<ll> tree;
vector<ll> arr;

ll init(int node, int start, int end){
  if(start == end)
    return tree[node] = arr[start];
  else
    return tree[node] = init(node*2, start,(start+end)/2) + init(node*2 +1, (start+end)/2 +1, end);
}

ll sum(int node, int start, int end, int left, int right){
  if(left > end || right <start){
    return 0;
  }else if(left <= start && end <= right){
    return tree[node];
  }else{
    return sum(node*2, start,(start+end)/2, left,right ) + sum(node*2+1, (start+end)/2 +1, end , left,right );
  }
} 

void update(int node,int start, int end,int index, ll diff){
  if(index < start || end < index)
    return;
  tree[node] += diff;
  if(start != end){ //리프노드가 아닌경우
    update(node *2, start,(start + end)/2, index, diff);
    update(node *2+1, (start + end)/2 +1,end, index, diff);
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin>>N>>M>>K;
  arr = vector<ll>(N);
  int h = (int)ceil(log2(N));
  tree = vector<ll>(1<<(h+1));
  M+=K;

  for(int i=0; i<N ; ++i)
    cin>>arr[i];
  init(1, 0,N-1);

  int a,b;
  while(M--){
    cin>>a>>b;
    if(a==1){
      ll c;
      cin>>c;
      update(1, 0, N-1, b-1, c - arr[b-1] );
      arr[b-1] = c;
    }
    else if(a==2){
      int c;
      cin>>c;
      cout<<sum(1, 0, N-1, b-1, c-1)<<'\n';
    }
  }
  return 0;
}
