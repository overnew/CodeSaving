//https://www.acmicpc.net/problem/1158
//큐에 넣어 죽이지 않을땐 pop하고 다시 뒤로 push

#include <iostream>
#include <queue>
using namespace std;

int main() {
  int n,k;
  int cnt=1;
  queue<int> arr;
  queue<int> sol;
  ios_base::sync_with_stdio(0);
  cin>>n>>k;

  for(int i=1; i<=n ; ++i){
    arr.push(i);
  }

  while(!arr.empty()){
    if(cnt == k){
      sol.push(arr.front());
      arr.pop();
      cnt=1;
    }else{
      arr.push(arr.front());
      arr.pop();
      ++cnt;
    }
  }

  cout<<'<';
  while(!sol.empty()){
    if(sol.size() == 1)
      cout<<sol.front();
    else
      cout<<sol.front()<<", ";
    sol.pop();
  }
  cout<<">\n";

  return 0;
}
