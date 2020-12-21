//https://www.acmicpc.net/problem/2812
#include <iostream>
#include<string>
#include <stack>
using namespace std;

int main() {
  //ios_base::sync_with_stdio(0);

  int num_size, erasable_num;
  stack<int> st;
  string number;
  
  cin>>num_size>>erasable_num;
  cin>>number;

  for(int idx=0; idx<num_size ; ++idx){
    while( !st.empty() && number[idx]-'0' > st.top()&& erasable_num>0){
      st.pop();
      --erasable_num;
    }
    st.push(number[idx]-'0' );
  }
  
  while(erasable_num>0){
    st.pop();
    --erasable_num;
  }

  stack<int> answer_st;
  while(!st.empty()){
    answer_st.push(st.top());
    st.pop();
  }

  while(!answer_st.empty()){
   cout<<answer_st.top();
    answer_st.pop();
  }
  cout<<'\n';

  return 0;
}
