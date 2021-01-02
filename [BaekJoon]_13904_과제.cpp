//https://www.acmicpc.net/problem/13904
#include <iostream>
#include<string.h>
#include<algorithm>
#include<vector>
using namespace std;

int main() {
  //ios_base::sync_with_stdio(0);
  int assignment_num,day,score;
  bool pos_assignment[1000];
  vector<pair<int,int>> assignment_list;
  
  cin>>assignment_num;

  for(int i=0; i<assignment_num ; ++i){
    cin>>day>>score;
    assignment_list.push_back(make_pair(day, score));
  }

  sort(assignment_list.begin(), assignment_list.end(),greater());
  memset(pos_assignment, true, sizeof(pos_assignment));
  
  int pos_assignment_idx = 0;
  int sum=0, max_score;

  for(int day_cnt = assignment_list[0].first ; day_cnt >=1 ; --day_cnt ){

    while(day_cnt <= assignment_list[pos_assignment_idx].first)
      ++pos_assignment_idx;

    max_score = 0;
    int selected_idx;
    
    max_score = assignment_list[0].second;
    selected_idx =0;

    for(int idx=1; idx<pos_assignment_idx ; ++idx){
      if(assignment_list[idx].second > max_score){
        max_score = assignment_list[idx].second;
        selected_idx = idx;
      }
    }

    sum += max_score;
    assignment_list[selected_idx].second =0;
  }
  cout<<sum<<'\n';

  return 0;
}
