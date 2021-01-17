//https://www.acmicpc.net/problem/1322
#include <iostream>
using namespace std;

typedef long long ll;

int main() {
  ll X,K;
  cin>>X>>K;

  ll zero_cnt =0, order;
  for(order=0;  ; ++order){
    if(!(X & ((ll)1<<order) )){ // 해당order의 bit가 0인 경우
      ++zero_cnt;
      if( ((ll)1 << zero_cnt)-1 >= K)
        break;
    }
  }

  ll Y =0;
  while(order>=0 && zero_cnt>0 && K>0){
    if(!(X & ((ll)1<<order) )){
      
      if(((ll)1 << (zero_cnt-1)) <= K){
        Y |= ((ll)1<<order);
        K = K - ((ll)1 << (zero_cnt-1));
      }

      --zero_cnt;
    }
    --order;
  }

  cout<<Y<<'\n';
  return 0;
}
