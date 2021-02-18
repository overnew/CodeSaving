//https://www.acmicpc.net/problem/13334
#include<queue>
#include<vector>
#include<cstdio>
#include<algorithm>
using namespace std;

int people_num, rail_len;
pair<int,int> arr[100000];

struct Cmp{
  bool operator()(const pair<int,int>& a,const pair<int,int>& b ){
    if(a.first == b.first)
      return a.second > b.second;
  
    return a.first > b.first;
  }
};

bool Compare(const pair<int,int>& a,const pair<int,int>& b ){
  if(a.second == b.second)
    return a.first < b.first;
  
  return a.second < b.second;
}

priority_queue<pair<int,int>, vector<pair<int,int>>, Cmp> min_pq;

int main(){
  scanf("%d", &people_num);

  int fr,se;
  for(int i=0; i< people_num ; ++i){
    scanf("%d %d", &fr, &se);
    if(fr >se)
      swap(fr,se);
    arr[i].first= fr;
    arr[i].second = se;
  }
  sort(arr, arr+people_num, Compare);

  scanf("%d", &rail_len);

  int start,end;
  int include_cnt=0,max_result =0; 
  
  for(int i=0; i< people_num ; ++i){
    end = arr[i].second;
    start = end - rail_len;

    while(!min_pq.empty() && min_pq.top().first < start ){
      --include_cnt;
      min_pq.pop();
    }

    if(arr[i].first >= start ){
      ++include_cnt;
      min_pq.push(arr[i]);

      max_result = max(max_result, include_cnt);
    }

  }
  printf("%d\n", max_result);

  return 0;
}
