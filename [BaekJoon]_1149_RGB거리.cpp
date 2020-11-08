//https://www.acmicpc.net/problem/1149
#include <iostream>
#include<string.h>
using namespace std;

int house_num;
int paint_costs[1000][3];
int min_cost[1000][3];

int paintHouse(int color_num, int house_idx){
  if(house_idx == house_num -1)
   return paint_costs[house_idx][color_num];

  int& ret = min_cost[house_idx][color_num];
  if(ret != -1)
    return ret;

  int min = 10000000;
  int temp;

  for(int i=0; i<3 ; ++i){
    if(i == color_num)
      continue;

    temp = paintHouse(i, house_idx+1) + paint_costs[house_idx][color_num];
    
    min = min< temp ? min : temp;
  }

  ret = min;
  return ret;
}

int main() { 
  cin>>house_num;

  for(int i=0; i<house_num ; ++i)
    for(int j=0; j<3 ; ++j)
      cin>>paint_costs[i][j];

  memset(min_cost, -1, sizeof(min_cost));
    
  int temp, min = 10000000;
  for(int i=0; i<3 ; ++i){
    temp = paintHouse(i, 0);
    
    min = min< temp ? min : temp;
  }

  cout<<min<<'\n';

  return 0;
}
