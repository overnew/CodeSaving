//https://www.acmicpc.net/problem/2504

/*
  괄호의 시작마다 재귀를 호출해 값을 계산.
*/

#include <iostream>
#include<stack>
#include<string>
using namespace std;

string s;
bool correct= true;
int idx =0;

int value(){
  stack<char> st;
  int sum=0;
  
  st.push(s[idx]);

  while(!st.empty() && idx < s.size()){
    ++idx;
    if(s[idx] == '(' ||s[idx] == '['){ //여는 괄호가 있으면 재귀를 호출해 그 괄호의 값을 sum에 추가
      sum+= value();
    }else if(s[idx] == ')'){
      if(st.top() == '('){
        st.pop();
        if(!sum) //sum=0
          return 2;
        else
          return 2*sum;
      }else{
        correct = false;
        idx = s.size();
      }
    }else{
      if(st.top() == '['){
        st.pop();
        if(!sum) //sum=0
          return 3;
        else
          return 3*sum;
      }else{
        correct = false;
        idx = s.size();
      }
    }
    
  }
  return 0;
}

int main() {
  int sum=0;
  cin>>s;

  while(idx<s.size()){
    if(s[idx] == ']' ||s[idx] == ')'){ 시작이 닫는 괄호면 당연히 아님
    correct = false;
    idx = s.size();
    }
    sum+=value();
    ++idx; //(()[[]])([])과 같이 여러개의 큰괄호로 떨어저 있는 경우를 위해 X+Y인 경우
  }

  if(correct)
    cout<<sum<<endl;
  else
    cout<<0<<endl;

  return 0;
}
