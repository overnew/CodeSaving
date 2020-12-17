//https://www.acmicpc.net/problem/1946
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
  ios_base::sync_with_stdio(0);

  int test_num,applicant_num;
  int fr,se;
  cin>>test_num;

  for(int i=0; i<test_num ; ++i){
    vector<pair<int, int>> ranking_list;

    cin>>applicant_num;
    for(int idx=0; idx<applicant_num ; ++idx){
      cin>>fr>>se;
      ranking_list.push_back(make_pair(fr,se));
    }

    sort(ranking_list.begin(), ranking_list.end());

    int cnt =1;
    int min_ranking = ranking_list[0].second;
    for(int idx=1 ; idx<applicant_num ; ++idx){
      if(min_ranking > ranking_list[idx].second){
        ++cnt;
        min_ranking = ranking_list[idx].second;
      }
    }
    cout<<cnt<<'\n';
  }

  return 0;
}
