//https://www.acmicpc.net/problem/2098
#include <iostream>
#include<string.h>
using namespace std;

int city_num;
int travel_cost[16][16];
int cache[16][16][(1<<16) -1];
const int MAXN = 17000001;

int TravelCities( int start_city,int now_city, int visited, int visited_num){

  if(visited_num >= city_num){
    if(travel_cost[now_city][start_city] != 0)
      return travel_cost[now_city][start_city];
    else
      return MAXN;
  }
  
  int& ret = cache[start_city][now_city][visited];
  if(ret != -1)
    return ret;
  
  ret  = MAXN;
  for(int i=0; i< city_num ; ++i)
    if(( ~visited & (1<<i) ) && travel_cost[now_city][i] !=0)
      ret = min(ret , TravelCities(start_city,i, visited |(1<<i), visited_num+1) + travel_cost[now_city][i]);
    
  
  return ret;
}

int main() {
  cin>>city_num;
  for(int i=0; i<city_num; ++i)
    for(int j=0; j<city_num ; ++j)
      cin>>travel_cost[i][j];
  
  memset(cache, -1, sizeof(cache));
  
  int result =MAXN;

  for(int i=0; i<city_num ; ++i)
    result = min(result, TravelCities(i, i, 1<<i, 1));
  
  cout<<result<<'\n';
  return 0;
}
