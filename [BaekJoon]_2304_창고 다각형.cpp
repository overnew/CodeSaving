//https://www.acmicpc.net/problem/2304
#include <iostream>
#include<vector>
#include<stack>
#include<cmath>
#include<algorithm>
using namespace std;

int pillar_num;

int RoofWidth(stack<pair<int,int>>& st){
  int width_sum=0;
  pair<int,int> now_pillar,next_pillar;

  while(st.size() >1){
    now_pillar = st.top();
    st.pop();
    next_pillar = st.top();
    width_sum += abs(now_pillar.first - next_pillar.first)*next_pillar.second;
  }

  return width_sum;
}

int main(){
  ios_base::sync_with_stdio(0);
  cin>>pillar_num;

  vector<pair<int,int>> v;
  stack<pair<int,int>> st_left , st_right;

  int fr,se, max_h =0;
  for(int i=0; i<pillar_num ; ++i){
    cin>>fr>>se;
    max_h = max(se,max_h);
    v.push_back(make_pair(fr, se));
  }

  sort(v.begin(),v.end());

  int left_end, right_end;
  for(int i=0; i<pillar_num ; ++i){
    if(v[i].second == max_h){
      left_end = i;
      break;
    }
  }

  for(int i=pillar_num-1; i>=0 ; --i){
    if(v[i].second == max_h){
      right_end = i;
      break;
    }
  }

  if(left_end != 0){
    st_left.push(v[0]);
    for(int i=1; i<left_end ; ++i)
      if(st_left.top().second < v[i].second)
        st_left.push(v[i]);

    st_left.push(v[left_end]);
  }

  if(right_end != pillar_num-1){
    st_right.push(v[pillar_num-1]);
    for(int i=pillar_num-2; i>right_end ; --i)
      if(st_right.top().second < v[i].second)
        st_right.push(v[i]);

    st_right.push(v[right_end]);
  }

  int width_sum =0;
  width_sum += RoofWidth(st_left);
  width_sum += RoofWidth(st_right);
  width_sum += (v[right_end].first  -v[left_end].first +1)* v[right_end].second;

  cout<<width_sum<<'\n';
  return 0;
}
