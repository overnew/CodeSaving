//https://www.acmicpc.net/problem/2515
#include<iostream>
#include<vector>
#include<string.h>
#include<algorithm>
using namespace std;

int picture_num, selling_height;
vector<int> dp, limit;
vector<pair<int,int>> pictures;

int main(){
  ios_base::sync_with_stdio(0);
  cin>>picture_num>>selling_height;

  dp.resize(picture_num+1);
  limit.resize(picture_num+1);
  pictures = vector<pair<int,int>>(picture_num+1);

  int height, cost;
  pictures[0] = {0,0};
  for(int i=1; i<=picture_num ; ++i){
    cin>>height>>cost;
    pictures[i] = {height, cost}; 
  }

  sort(pictures.begin(), pictures.end());

  for(int idx=1; idx<=picture_num ; ++idx){
    for(limit[idx] = limit[idx-1]; limit[idx] <idx ; ++limit[idx])
      if(pictures[idx].first - pictures[limit[idx]].first < selling_height) break;
    --limit[idx];
  }

  for(int idx=1; idx<=picture_num ; ++idx)
    dp[idx] = max(dp[idx-1], dp[limit[idx]] + pictures[idx].second);

  cout<<dp[picture_num]<<'\n';
  return 0;
}
