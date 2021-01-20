//https://www.acmicpc.net/problem/3020
#include <iostream>
#include<string.h>
using namespace std;

int cave_len,cave_height;
int section_up[500001];
int section_down[500001];

int main() {
  cin>>cave_len>>cave_height;
  memset(section_up, 0 , sizeof(section_up));
  memset(section_down, 0 , sizeof(section_down));

  int temp;
  for(int idx=0; idx<cave_len ; ++idx){
    cin>>temp;
    if(idx % 2 ==0)
      ++section_down[temp];
    else
      ++section_up[cave_height -temp +1];
  }

  for(int h=cave_height-1; h>0; --h)
    section_down[h] += section_down[h+1];

  for(int h=2; h<=cave_height ; ++h)
    section_up[h] += section_up[h-1];

  int cnt =0, min_result=200001;
  for(int h=1; h<=cave_height ; ++h){
    if(section_up[h] + section_down[h] == min_result){
      ++cnt;
    }else if(section_up[h] + section_down[h] < min_result){
      cnt =1;
      min_result = section_up[h] + section_down[h];
    }
  }

  cout<<min_result<<" "<<cnt<<"\n";
  return 0;
}
