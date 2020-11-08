//https://www.acmicpc.net/problem/2579
#include <iostream>
#include<string.h>
using namespace std;

int stair_num;
int stair_scores[300];
int max_stair[300][2];

int ascendStair(int stair_idx,int succession){
  if(stair_idx == stair_num-1)
    return stair_scores[stair_num-1];

  int& ret = max_stair[stair_idx][succession];
  if(ret != -1)
    return ret;
  
  int max = 0;
  int temp;

  if(succession !=2){ //3개 이상이 연속으로 선택됨을 방지
    temp = ascendStair(stair_idx+1, succession+1) + stair_scores[stair_idx];
    max = max> temp ? max: temp;
  }

  if(stair_idx < stair_num -2){
    temp = ascendStair(stair_idx+2, 1)+ stair_scores[stair_idx];
    max = max> temp ? max: temp;
  }

  ret = max;
  return ret;
}

int main() { 
  cin>>stair_num;

  for(int i=0; i<stair_num ; ++i)
    cin>>stair_scores[i];

  memset(max_stair, -1, sizeof(max_stair));

  int max =0;
  int temp;
  temp = ascendStair(0, 1);
  max = max> temp ? max: temp;
  temp = ascendStair(1, 1);
  max = max> temp ? max: temp;

  cout<<max<<'\n';
  return 0;
}
