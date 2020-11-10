//https://www.acmicpc.net/problem/2294
#include <iostream>
#include<string.h>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> coin_value;
int cache[10001];
int coin_num, goal_value;

int main() { 
  cin>>coin_num>>goal_value;

  int temp;
  for(int i=0; i<coin_num ; ++i){
    cin>>temp;
    if(temp <=10000 )
      coin_value.push_back(temp);
  }
  sort(coin_value.begin() , coin_value.end());
  memset(cache, -1, sizeof(cache));
  
  queue<int> sum_que;
  for(int i=0; i<coin_value.size() ;++i){
    cache[coin_value[i]] =1;
    sum_que.push(coin_value[i]);
  }

  int sum_now;
  while(!sum_que.empty() && cache[goal_value] == -1){
    sum_now = sum_que.front();
    sum_que.pop();

    for(int i=0; i<coin_value.size() ; ++i)
      if( sum_now + coin_value[i]<=10000 && cache[sum_now + coin_value[i]] == -1){ //아직 방문하지 않았다면
        cache[sum_now + coin_value[i]] = cache[sum_now] +1;
        sum_que.push(sum_now + coin_value[i]);
      }
  }

  cout<<cache[goal_value]<<"\n";
  return 0;
}
