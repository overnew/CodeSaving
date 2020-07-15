//https://www.acmicpc.net/problem/10845
//stl의 큐에 익숙해지자

#include <iostream>
#include<queue>
#include<string>
using namespace std;

int main() {
  int n,num;
  string com;
  queue<int> q;
  ios_base::sync_with_stdio(0);
  cin>>n;

  for(int i=0; i<n ; ++i){
    cin>>com;

    if(com =="push"){
      cin>>num;
      q.push(num);

    }else if(com =="pop"){
      if(q.empty())
        cout<<-1<<endl;
      else{
        cout<<q.front()<<endl;
        q.pop();
      }

    }else if(com =="size"){
      cout<<q.size()<<endl;

    }else if(com =="empty"){
      cout<<q.empty()<<endl;

    }else if(com =="front"){
      if(q.empty())
        cout<<-1<<endl;
      else
        cout<<q.front()<<endl;
    }else if(com =="back"){
      if(q.empty())
        cout<<-1<<endl;
      else
        cout<<q.back()<<endl;
    }
  }

  return 0;
}
