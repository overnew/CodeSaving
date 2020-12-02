//https://www.acmicpc.net/problem/2629
#include <iostream>
#include<string.h>
using namespace std;

int main() {
  int weight_num, marble_num;
  int weight_list[31], marble_list[7];
  bool dp[40001][31];
  bool is_pos_marble[7];

  cin>>weight_num;
  for(int i=1; i<=weight_num ; ++i)
    cin>>weight_list[i];
  
  cin>>marble_num;
  for(int i=0; i<marble_num ; ++i)
    cin>>marble_list[i];

  memset(dp, false, sizeof(dp));
 
  for(int i=0; i<=weight_num ; ++i)
    dp[0][i] = true;

  for(int weight=1; weight<=40000 ;++weight )
    for(int idx=1; idx<=weight_num ; ++idx){
      if(weight - weight_list[idx] >=0)
        dp[weight][idx] |= dp[weight - weight_list[idx]][idx-1];

      dp[weight][idx] |= dp[weight][idx-1];
    }

  memset(is_pos_marble, false, sizeof(is_pos_marble));
  for(int i=0; i<marble_num ; ++i)
    for(int weight=1; weight<=40000-marble_list[i] ;++weight)
      if(dp[weight][weight_num] && dp[weight+marble_list[i]][weight_num])
        is_pos_marble[i] = true;

  for(int i=0; i<marble_num ; ++i){
    if(dp[marble_list[i]][weight_num] || is_pos_marble[i])
      cout<<"Y ";
    else
      cout<<"N ";
  }
  cout<<'\n';

  return 0;
}
