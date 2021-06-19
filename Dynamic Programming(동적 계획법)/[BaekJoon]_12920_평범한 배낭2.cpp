//https://www.acmicpc.net/problem/12920
#include<iostream>
#include<vector>
#include<string.h>
#include<algorithm>
using namespace std;

int item_variety, bag_capacity, item_num;
int dp[10001][2020];
vector<pair<int,int>> divided_item;

int main(){
  ios_base::sync_with_stdio(0);
  cin>>item_variety>>bag_capacity;
  memset(dp, 0 ,sizeof(dp));

  //빈칸 넣어두기
  divided_item.push_back({0, 0});

  int w, c, k;
  for(int i=0; i<item_variety ; ++i){
    cin>>w>>c>>k;

    //물건을 제곱 수로 나누어주자
    for(int i=k; i>0 ; i >>=1){
      int part = i -(i>>1);
      divided_item.push_back({w*part, c*part});
    }
  }

  for(int cap = 1; cap <= bag_capacity ; ++cap){
    for(int idx =1; idx < divided_item.size() ; ++idx){
      dp[cap][idx] = dp[cap][idx-1];

      //idx번째 물건을 담을 수 있는 경우
      if(cap >= divided_item[idx].first)
        dp[cap][idx] = max(dp[cap][idx], dp[cap - divided_item[idx].first][idx -1] + divided_item[idx].second);
    }
  }

  cout<<dp[bag_capacity][ divided_item.size()-1]<<"\n";
  return 0;
}
