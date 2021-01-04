//https://www.acmicpc.net/problem/2513
#include <iostream>
#include<algorithm>
#include<vector>
#include<math.h>
using namespace std;
int apart_num, capacity, school_pos;

int CalcShortestRoute(vector<pair<int,int>>& ret_v){
  int len_sum=0, left_sit = capacity;
  int far_idx = 0,far_len =0;

  while(far_idx < ret_v.size()){
    if(left_sit > 0){
      far_len = max(far_len, ret_v[far_idx].first);
    }

    if(left_sit > ret_v[far_idx].second){
      left_sit -= ret_v[far_idx].second;
      ret_v[far_idx].second=0;
      ++far_idx;
    }else if(left_sit < ret_v[far_idx].second){
      ret_v[far_idx].second -= left_sit;
      left_sit=0;
    }
    else{
      ret_v[far_idx].second=0;
      left_sit=0;
      ++far_idx;
    }

    if(left_sit == 0 || far_idx>=ret_v.size()){
      len_sum += 2*far_len;
      far_len= 0;
      left_sit = capacity;
    }
    
  }
  return len_sum;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin>>apart_num>>capacity>>school_pos;

  vector<pair<int,int>> v,left_v,right_v;
  int pos,num;
  for(int i=0; i<apart_num ; ++i){
    cin>>pos>>num;
    v.push_back(make_pair(pos,num));
  }

  for(vector<pair<int,int>>::iterator it = v.begin() ; it <v.end() ; ++it){ 
    if(it->first < school_pos )
      left_v.push_back(make_pair( abs(school_pos - it->first),it->second));
    else
      right_v.push_back(make_pair( abs(school_pos - it->first),it->second));
  }

  sort(left_v.begin(), left_v.end(),greater());
  sort(right_v.begin(), right_v.end(),greater());

  cout<<CalcShortestRoute(left_v) + CalcShortestRoute(right_v)<<'\n';
  return 0;
}
