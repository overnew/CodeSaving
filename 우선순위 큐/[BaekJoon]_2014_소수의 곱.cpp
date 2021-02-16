//https://www.acmicpc.net/problem/2014
#include<queue>
#include<iostream>
using namespace std;

int prime_num;
long long primes[100];
int order;
priority_queue<int, vector<int>, greater<int>> min_pq;

int main(){
  cin>>prime_num>>order;

  for(int i=0; i<prime_num ; ++i){
    cin>>primes[i];
    min_pq.push(primes[i]);
  }

  int count =0 ;
  long long prev_num=0;
  long long result;

  while(count != order){
    while(prev_num == min_pq.top()){
      min_pq.pop();
    }
    for(int i=0; i<prime_num ; ++i){
      result = primes[i] * min_pq.top();
      if(result >= INT32_MAX)
        break;
      min_pq.push(result);
    }
    prev_num = min_pq.top();
    min_pq.pop();
    ++count;
  }

  cout<<prev_num<<'\n';

  return 0;
}
