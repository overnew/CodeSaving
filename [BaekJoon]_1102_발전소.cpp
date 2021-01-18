//https://www.acmicpc.net/problem/1102
#include <iostream>
#include<string.h>
#include<string>
using namespace std;

const int MAXN = (1<<16 )-1;
int station_num;
int start_cost[16][16];
int least_num;
int cache[MAXN];

int TurnOnStation(int turned_num, int state){
  if(turned_num>= least_num)
    return 0;
  
  int& ret = cache[state];
  if(ret != -1)
    return  ret;
  
  ret = 800;
  int min_cost= 51;
  for(int j =0; j <station_num ; ++j){
    if( ~state & (1<<j) ){    //j번째 발전소가 꺼져있는 경우(0인 경우)
      for(int i=0; i<station_num ; ++i){
        if(state & (1<<i))    //i번째 발전소가 켜져있는 경우(1인 경우)
          min_cost = min(min_cost, start_cost[i][j]);
      }

      ret = min(ret, TurnOnStation(turned_num+1, state|(1<<j) ) + min_cost);
      min_cost = 51;
    }
  }

  return ret;
}

int main() {
  string st;
  int station_state=0,turned_on=0;
  cin>>station_num;

  for(int i=0; i<station_num ; ++i)
    for(int j=0; j<station_num ; ++j)
      cin>>start_cost[i][j];
  
  cin>>st>>least_num;
  for(int i=0; i<station_num ;++i){
    if(st[i] =='Y'){
      station_state |= (1<<i);
      ++turned_on;
    }
  }
  if(station_state ==0){
    if(least_num ==0)
      cout<<"0\n";
    else
      cout<<"-1\n";
    return 0;
  }

  memset(cache, -1, sizeof(cache));
  cout<<TurnOnStation(turned_on, station_state)<<"\n";
  return 0;
}
