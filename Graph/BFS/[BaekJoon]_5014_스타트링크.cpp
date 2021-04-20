//https://www.acmicpc.net/problem/5014
#include<iostream>
#include<queue>
#include<string.h>
using namespace std;

const int MAXN = 1000001;
int F,S,G,U,D;
int min_push[MAXN];

int PushButtonBFS(int start_floor){
  queue<int> que;
  que.push(start_floor);
  min_push[start_floor] = 0;

  int floor, up_floor, down_floor, next_cost;
  while(!que.empty()){
    floor = que.front();
    que.pop();
    
    if(floor == G)
      return min_push[floor];

    up_floor = floor +U;
    down_floor = floor - D;
    next_cost = min_push[floor] +1;
    if(up_floor <=F && min_push[up_floor] == -1){
      que.push(up_floor);
      min_push[up_floor] = next_cost;
    }

    if(down_floor >=1 && min_push[down_floor] == -1){
      que.push(down_floor);
      min_push[down_floor] = next_cost;
    }
  }

  return -1;
}

int main(){
  ios_base::sync_with_stdio(0);
  cin>>F>>S>>G>>U>>D;

  memset(min_push, -1, sizeof(min_push) );

  int result = PushButtonBFS(S);
  if(result == -1)
    cout<<"use the stairs\n";
  else
    cout<<result<<"\n";

  return 0;
}
