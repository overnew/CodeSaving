//https://www.acmicpc.net/problem/1495
#include <iostream>
#include<string.h>
using namespace std;

int song_num;
int start_volume;
int max_volume;
int volume_list[101];
int cache[101][1001];

int findMaxVolume(int order,int volume){
  if(order == song_num)
    return volume;
  
  int& ret = cache[order][volume];

  if(ret != -1)
    return ret;
  
  if(volume - volume_list[order+1] >=0)
    ret = max(ret, findMaxVolume(order+1,volume - volume_list[order+1]));

  if(volume + volume_list[order+1] <= max_volume)
    ret = max(ret, findMaxVolume(order+1,volume + volume_list[order+1]));
  
  if(ret == -1)
    ret = -2;
  
  return ret;
}

int main() { 
  cin>>song_num>>start_volume>>max_volume;

  for(int i=1; i<=song_num ; ++i)
    cin>>volume_list[i];

  memset(cache , -1, sizeof(cache));
  int max_result= findMaxVolume(0, start_volume);

  if(max_result == -2)
    cout<<"-1\n";
  else
    cout<<max_result<<'\n';
  return 0;
}
