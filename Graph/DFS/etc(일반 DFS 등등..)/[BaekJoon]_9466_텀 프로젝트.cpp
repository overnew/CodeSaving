//https://www.acmicpc.net/problem/9466
#include<iostream>
#include<string.h>
using namespace std;

int student_num;
int choice_partner[100001];
bool visited[100001];
int cnt;

pair<int,int> PartnerDFS(int idx,int depth){
  if(visited[idx])
    return make_pair(idx,depth);
  visited[idx] =true;

  pair<int,int> ret = PartnerDFS(choice_partner[idx], depth+1);
  if(ret.first == idx)
    cnt -=  ret.second - depth;

  return ret;
}

int main(){
  ios_base::sync_with_stdio(0);
  int test_num;
  cin>>test_num;
  
  while(test_num--){
    cin>>student_num;
    cnt = student_num;

    memset(visited, false, sizeof(visited));

    for(int i=1; i<=student_num ; ++i)
      cin>>choice_partner[i];
    
    for(int i=1; i<=student_num ; ++i)
      if(!visited[i])
        PartnerDFS(i, 1);
    
    cout<<cnt<<'\n';
  }

  return 0;
}
