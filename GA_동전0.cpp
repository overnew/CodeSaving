//https://www.acmicpc.net/problem/11047
//문제 좀 제대로 읽자 ㅡㅡ; N이 최대 100,000,000인줄 알아서 메모리 초과가 남

/*
  count += wallet/value[i]; //몫을 count해주고
  wallet %= value[i]; //이제 다음엔 그 나머지만 계산하면 
  이와 같이 하면 단순 빼기보다 훨씬 빠르게 계산 가능
*/


#include <iostream>
using namespace std;

int N;
int K;
int value[10];

int Coin(){
  int idx = N-1;
  int wallet =K;
  int count=0;

  while(idx >=0 && wallet!=0){
    while(value[idx]<= wallet){
      wallet -= value[idx];
      ++count;
    }
    --idx;
  } 

  return count;
}

int main() {
  cin>> N >>K;

  for(int i=0; i<N ; ++i){
    cin>>value[i];
  }

  cout<<Coin()<<endl;

  return 0;
}
