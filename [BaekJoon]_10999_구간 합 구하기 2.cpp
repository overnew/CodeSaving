//https://www.acmicpc.net/problem/10999
#include <iostream>
#include<cstdio>
#include<vector>
#include<cmath>
using namespace std;

vector<long long> tree;
vector<long long> lazy;
long long arr[1000001];

int arr_size;

long long init(int node, int start,int end){
  if(start == end){
    return tree[node] = arr[start];
  }else{
    return tree[node] = init(node*2, start, (start+end)/2) + init(node*2 +1, (start + end)/2 +1, end);
  }
}

void updateLazy(int node, int start, int end){
  if(lazy[node] != 0){
    tree[node] += (end - start +1)*lazy[node];
    if(start != end){ //리프노드가 아닌경우
      lazy[node*2] += lazy[node];
      lazy[node*2 +1] += lazy[node];
    }
    lazy[node] =0;
  }
}

void updateRange(int node, int start, int end, int left, int right, long long diff){
  updateLazy(node, start,end);
  if(right < start || end < left){
    return;
  }else if(left <= start && end <= right){
    tree[node] += (end - start +1)*diff;
    if(start != end){
      lazy[node*2] += diff;
      lazy[node*2+1] += diff;
    }
    return;
  }
  updateRange(node*2, start, (start +end)/2, left,right, diff);
  updateRange(node*2+1,(start +end)/2 +1, end, left,right, diff);
  tree[node] = tree[node*2] + tree[node*2 +1];
  return;
} 

long long sum(int node, int start, int end, int left, int right){
  updateLazy(node, start, end);
  if(right < start || end < left){
    return 0;
  }else if(left <= start && end <= right){
    return tree[node];
  }
  return sum(node*2, start, (start+ end)/2, left, right) + sum(node*2 +1, (start+ end)/2 +1, end, left, right);
}

int main(){
  int M,K;
  scanf("%d %d %d", &arr_size,&M,&K);
  M += K;

  int h = (int)ceil(log2(arr_size));
  tree = vector<long long>(1<<(h+1));
  lazy = vector<long long>(1<<(h+1));

  for(int i=1; i<=arr_size ; ++i)
    scanf("%lld", &arr[i]);
  init(1,1,arr_size);

  int a,b,c;
  long long d;
  while(M--){
    scanf("%d",&a);
    if(a == 1){
      scanf("%d %d %lld",&b,&c,&d);
      updateRange(1, 1, arr_size, b, c, d);
    }else{
      scanf("%d %d",&b,&c);
      printf("%lld\n",sum(1,1,arr_size,b,c));
    }
  }

  return 0;
}
