//https://www.acmicpc.net/problem/1966

#include <iostream>
#include<queue>
#include<string>
using namespace std;

int main() {
  int test,n,m,temp;
  int num;
  priority_queue<int> pq;
  cin>>test;

  for(int i=0; i<test ; ++i){
    cin>> n>>m;

    for(int i=0; i<n ; ++i){
      cin>>temp;
      pq.push(temp);
    }

    for(int i=0; i<n ; ++i){
      if(pq.top() == m) //이렇게 하면 
    }
  }


  return 0;
}
