//https://www.acmicpc.net/problem/12865
#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
  int item_num, limit_weight;
  int dp[100001][101];
  vector<pair<int,int>> item_list;
  cin>>item_num>>limit_weight;

  int fr,se;
  item_list.push_back(make_pair(0, 0));
  for(int i=0; i<item_num ; ++i){
    cin>>fr>>se;
    item_list.push_back(make_pair(fr,se));
  }
  sort(item_list.begin(), item_list.end());

  int result,max_value;
  for(int i=0; i<=item_num ; ++i)
    dp[0][i]=0;

  for(int i=0; i<=limit_weight ; ++i)
    dp[i][0]=0;

  for(int weight=1; weight<=limit_weight ; ++weight){
    for(int idx=1; idx<=item_num ; ++idx){
      max_value =0 ;
      if(weight -item_list[idx].first >=0){
        result = dp[weight - item_list[idx].first][idx-1] + item_list[idx].second;
        max_value = max(max_value,result);
      }
      result = dp[weight][idx-1];
      max_value = max(max_value,result);
      dp[weight][idx] = max_value;
    }
  }

  cout<<dp[limit_weight][item_num]<<'\n';
  return 0;
}
