//https://algospot.com/judge/problem/read/STRJOIN
#include <iostream>
#include <queue>
#include<vector>
using namespace std;

int string_num;
priority_queue<int,vector<int>,greater<int>> string_size_que;

int main() {
  ios_base::sync_with_stdio(0);

  int test_num,temp;
  cin>>test_num;

  for(int i=0; i<test_num ; ++i){
    cin>>string_num;
    for(int idx=0; idx<string_num ; ++idx){
      cin>>temp;
      string_size_que.push(temp);
    }
    
    int joined_size=0,sum =0;
    while(string_size_que.size() >=2){
      joined_size = string_size_que.top();
      string_size_que.pop();

      joined_size += string_size_que.top();
      string_size_que.pop();

      sum += joined_size;
      string_size_que.push(joined_size);
    }

    if(sum==0)
      cout<<string_size_que.top();
    else
      cout<<sum<<'\n';
    string_size_que.pop();
  }
  return 0;
}
