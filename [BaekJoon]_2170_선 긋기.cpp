//https://www.acmicpc.net/problem/2170
#include <iostream>
#include<algorithm>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int N;
  pair<int,int> points[1000000];
  cin>>N;
  
  int first,second;
  int sum_length=0;
  for(int i=0; i<N ; ++i){
    cin>>first>>second;
    points[i].first= first;
    points[i].second = second;
  }

  sort(points, points+N);

  int start_point = points[0].first, end_point = points[0].second;

  for(int i=1; i<N ; ++i){
    if(points[i].first > end_point){
      sum_length += end_point - start_point;
      start_point = points[i].first;
      end_point = points[i].second;
    }else if(points[i].second > end_point){
      end_point = points[i].second;
    }
  }

  sum_length += end_point - start_point;

  cout<<sum_length<<'\n';

  return 0;
}
