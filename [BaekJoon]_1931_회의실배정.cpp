//https://www.acmicpc.net/problem/1931
#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool Compare(pair<int,int>& a, pair<int,int>& b){
  return a.second < b.second;
}

int main() {
  ios_base::sync_with_stdio(0);

  vector<pair<int,int>> meeting_list;
  int meeting_num;
  cin>>meeting_num;

  int fr,se;
  for(int i=0; i<meeting_num ; ++i){
    cin>>fr>>se;
    meeting_list.push_back(make_pair(fr,se));
  }

  sort(meeting_list.begin(),meeting_list.end());
  sort(meeting_list.begin(),meeting_list.end(),Compare);

  int cnt=1;
  int pre_end = meeting_list[0].second;
  for(int idx=1; idx<meeting_num ; ++idx){
    if(meeting_list[idx].first>= pre_end){
      ++cnt;
      pre_end = meeting_list[idx].second;
    }
  }

  cout<<cnt<<'\n';
  return 0;
}
