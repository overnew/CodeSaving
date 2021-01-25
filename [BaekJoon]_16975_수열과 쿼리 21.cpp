//https://www.acmicpc.net/problem/16975
#include <iostream>
#include<string.h>
#include<cstdio>
using namespace std;

int arr_size;
long long tree[100001];

void update(int idx, long long num){
  for(int i= idx; i<=arr_size ; i += (i & -i))
    tree[i] += num;
}

long long sum(int idx){
  long long result =0;
  for(int i= idx; i>0 ; i -= (i & -i))
    result += tree[i];
  
  return result;
}

int main(){
  int query_num;
  long long prev_num, now_num;

  scanf("%d", &arr_size);
  memset(tree, 0 ,sizeof(tree));

  scanf("%lld", &prev_num);
  update(1,prev_num);
  for(int i=2; i<=arr_size ; ++i){
    scanf("%lld", &now_num);
    update(i, now_num - prev_num);
    prev_num =now_num;
  }

  scanf("%d", &query_num);

  int num,i,j,x;
  long long k;
  while(query_num--){
    scanf("%d", &num);
    if(num==1){
      scanf("%d %d %lld",&i,&j,&k);
      update(i, k);
      update(j+1, -k);
    }else{
      scanf("%d",&x);
     printf("%lld\n",sum(x));
    }
  }

  return 0;
}
