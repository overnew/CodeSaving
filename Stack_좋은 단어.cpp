//https://www.acmicpc.net/problem/3986

/*
  처음에는 stack의 size가 2보다 작을 때만 push해야한다 생각했는데 ABABBABA와 같은 배열을 처리하지 못했다.
  아래와 같이 그냥 TOP과 다르다면 그냥 push 해주고 최종적으로 비어있지  좋은단어!
*/

#include <iostream>
#include <stack>
#include<string>
using namespace std;

int main() {
  int n;
  int cnt =0;
  string st;
  
  cin>>n;

  for(int i=0; i<n ; ++i){
    cin>>st;
    int j=0;
    stack<char> ab;

    for(; j<st.size() ; ++j){

      if(ab.empty()){
        ab.push(st[j]);
      }
      else if(ab.top() == st[j]){
        ab.pop();

      }else {
        ab.push(st[j]);
      }
    }

    if( ab.empty())
      ++cnt;
    
    st.clear();

  }
  cout<<cnt<<endl;

  return 0;
}
