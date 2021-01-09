//https://www.acmicpc.net/problem/2613
#include <iostream>
#include<vector>
using namespace std;

int marble_num, group_num;
vector<int> marble_v;
vector<int> group_v;

int PosGroupNum(int limit){
  int marble_sum=0,group_count =0;

  for(int i=0; i<marble_v.size() ; ++i){
    marble_sum +=marble_v[i];
    if(marble_sum>limit){
      marble_sum =marble_v[i];
      group_count++;
    }
  }

  if(marble_sum>0)
    group_count++;
  
  return group_count;
}

void MakeGroup(int limit){
  int marble_sum=0,member_count=0,group_count =group_num;
  for(int i=0; i<marble_v.size() ; ++i){
    marble_sum +=marble_v[i];

    if(marble_sum>limit){
      marble_sum =marble_v[i];
      group_v.push_back(member_count);
      member_count=0;
      --group_count;
    }
    ++member_count;
    
    if(group_count ==marble_num -i){
      group_v.push_back(member_count);
      for(int j = marble_num -(i+1); j>0 ; --j)
        group_v.push_back(1);
        
      return;
    }

  }
  if(marble_sum>0)
    group_v.push_back(member_count);
}

int main() {
  ios_base::sync_with_stdio(0);
  cin>>marble_num>>group_num;

  int temp,marble_sum=0, max_marble=0;
  for(int i=0; i<marble_num ; ++i){
    cin>>temp;
    marble_v.push_back(temp);
    max_marble = max(max_marble, temp);
    marble_sum+= temp;
  }

  int mid_num,group_count=0;
  int left = max_marble, right = marble_sum;

  int group_result,answer=300000;
  while(left<=right){
    mid_num = (left+right)/2;
    group_result=PosGroupNum(mid_num);

    if(group_result> group_num){
      left = mid_num +1;
    }else{
      right = mid_num -1;
      if(mid_num < answer)
        answer = mid_num;
    }
  }

  cout<<answer<<'\n';
  MakeGroup(answer);
  for(int i=0; i<group_v.size() ; ++i)
    cout<<group_v[i]<<' ';
  
  cout<<'\n';
  return 0;
}
