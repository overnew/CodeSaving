//https://algospot.com/judge/problem/read/PASS486
#include <iostream>
#include<cmath>
using namespace std;

const int MAX_NUM = 10000000;

int min_factor[MAX_NUM+1];
int divisor_cnt[MAX_NUM+1];
int min_factor_pow[MAX_NUM+1];

void eratosthenes(int n){
  int sqrtn = int(sqrt(n));

  min_factor[0] = min_factor[1] = -1;
  for(int i=2; i<=n ; ++i)
    min_factor[i] = i;

  for(int i=2; i<=sqrtn ; ++i ){
    if(min_factor[i]==i) //이 경우에만 소수
      for(int j= i*i; j<=n ; j+= i)
        if(min_factor[j]==j)
          min_factor[j] = i;
  }
}

void CalcDivisorNum(){
  divisor_cnt[1] =1;

  for(int i=2; i<=MAX_NUM ; ++i){
    if(min_factor[i] == i){ //소수인 경우
      min_factor_pow[i] = 1;
      divisor_cnt[i] =2;
    }else{
      int p =min_factor[i];
      int m = i / p;
      if(p != min_factor[m])
        min_factor_pow[i] = 1;
      else
        min_factor_pow[i] = min_factor_pow[m] +1;
      int a =min_factor_pow[i];
      divisor_cnt[i] = (divisor_cnt[m]/a)*(a+1);
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  int divisor_num, lo,hi,test_num;
  cin>>test_num;

  eratosthenes(MAX_NUM);
  CalcDivisorNum();

  while(test_num--){
    cin>>divisor_num>>lo>>hi;

    int count =0;
    for(int i= lo; i<=hi ; ++i)
      if(divisor_cnt[i] == divisor_num)
        ++count;

    cout<<count<<'\n';
  }
  return 0;
}
