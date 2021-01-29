//https://algospot.com/judge/problem/read/ITES
#include <iostream>
#include<queue>
using namespace std;

int main(){
  ios_base::sync_with_stdio(0);

  int test_num, K,signal_size;
  cin>>test_num;

  int total_sum=0, cnt,input_num;
  long long signal, prev_singal,temp;

  while(test_num--){
    cin>>K>>signal_size;

    queue<int> que;  
    total_sum = cnt = 0;
    signal =1983;

    while(signal_size--){
      input_num = (int)(signal % 10000 +1);
      while(total_sum + input_num > K && !que.empty()){
        total_sum -= que.front();
        que.pop();
      }

      if(total_sum + input_num == K){
        ++cnt;
        if(!que.empty()){
          total_sum -= que.front();
          que.pop();
        }
        total_sum += input_num;
        que.push(input_num);
      }else if(total_sum + input_num < K){
        total_sum += input_num;
        que.push(input_num);
      }

      prev_singal = signal;
      signal = (prev_singal* 214013 + 2531011) %((long long)1<<32);
    }
    cout<<cnt<<'\n';
  }

  return 0;
}
