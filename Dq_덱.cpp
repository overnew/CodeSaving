//https://www.acmicpc.net/problem/10866

#include <iostream>
#include<deque>
#include<string>
using namespace std;

int main() {
  int n,temp;
  deque<int> dq;
  string st;
  cin>>n;

  for(int i=0; i<n ; ++i){
    cin>>st;

    if(st=="push_front"){
      cin>>temp;
      dq.push_front(temp);
    }else if(st=="push_back"){
      cin>>temp;
      dq.push_back(temp);
    }else if(st=="pop_front"){
      if(dq.empty())
        cout<<-1<<endl;
      else{
        cout<<dq.front()<<endl;
        dq.pop_front();
      }
    }else if(st=="pop_back"){
      if(dq.empty())
        cout<<-1<<endl;
      else{
        cout<<dq.back()<<endl;
        dq.pop_back();
      }
    }else if(st == "size"){
      cout<<dq.size()<<endl;
    }else if(st == "empty"){
      if(dq.empty())
        cout<<1<<endl;
      else 
        cout<<0<<endl;
    }else if(st=="front"){
      if(dq.empty())
        cout<<-1<<endl;
      else{
        cout<<dq.front()<<endl;
      }
    }else if(st=="back"){
      if(dq.empty())
        cout<<-1<<endl;
      else{
        cout<<dq.back()<<endl;
      }
    }

  }

  return 0;
}
