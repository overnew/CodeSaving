//https://www.acmicpc.net/problem/2098
#include <iostream>
#include<string.h>
using namespace std;

int city_num;
int travel_cost[16][16];
int cache[16][(1<<16) -1];
const int MAXN = 17000001;
int all_visit;

int TravelCities( int now_city, int visited){

  if(visited == all_visit){
    if(travel_cost[now_city][0] != 0)
      return travel_cost[now_city][0];
    else
      return MAXN;
  }
  
  int& ret = cache[now_city][visited];
  if(ret != -1)
    return ret;
  
  ret  = MAXN;
  for(int i=0; i< city_num ; ++i)
    if(( ~visited & (1<<i) ) && travel_cost[now_city][i] !=0)
      ret = min(ret , TravelCities(i, visited |(1<<i)) + travel_cost[now_city][i]);
    
  return ret;
}

int main() {
  cin>>city_num;

  all_visit =( 1<<city_num ) -1;
  for(int i=0; i<city_num; ++i)
    for(int j=0; j<city_num ; ++j)
      cin>>travel_cost[i][j];
  
  memset(cache, -1, sizeof(cache));
  cout<<TravelCities(0, 1)<<'\n';
  return 0;
}
