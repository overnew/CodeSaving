//https://www.acmicpc.net/problem/2164

#include <iostream>
#include<queue>
using namespace std;

int main() {
  int n;
  queue<int> q;
  cin>>n;

  for(int i=1; i<=n ; ++i){
    q.push(i);
  }

  while(q.size() !=1){
    q.pop();
    q.push(q.front());
    q.pop();
  }

  cout<<q.front()<<endl;

  return 0;
}
