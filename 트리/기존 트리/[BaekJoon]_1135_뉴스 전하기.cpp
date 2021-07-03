//https://www.acmicpc.net/problem/1135
#include<iostream>
#include<vector>
#include<string.h>
#include<algorithm>
using namespace std;

int employee_num;
vector<vector<int>> chilidren;

int MinPropaDFS(int idx){
  if(chilidren[idx].empty())
    return 0;

  vector<int> sub_answer;
  for(int i=0; i<chilidren[idx].size() ; ++i)
    sub_answer.push_back(MinPropaDFS(chilidren[idx][i]));
  
  sort(sub_answer.begin(), sub_answer.end(), greater());

  int ret = 0;
  for(int i=0; i<sub_answer.size() ; ++i)
    ret = max(ret, sub_answer[i] + (i+1));

  return ret;
}

int main(){
  ios_base::sync_with_stdio(0);
  cin>>employee_num;
  
  chilidren.resize(employee_num+1);
  
  int boss;
  for(int idx =0; idx<employee_num ; ++idx){
    cin>>boss;
    if(idx == 0)
      continue;
    chilidren[boss].push_back(idx);
  }

  cout<<MinPropaDFS(0)<<'\n';
  return 0;
}
