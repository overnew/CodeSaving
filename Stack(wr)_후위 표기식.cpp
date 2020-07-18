//https://www.acmicpc.net/problem/1918

#include <iostream>
#include <stack>
#include <vector>
#include<string>
using namespace std;

int main() {
  string st;
  vector<string> operand;
  stack<char> oper;
  string front;
  string back;

  cin>>st;
  st = '(' + st + ')';

  for(int i=0; i<st.size() ; ++i){
    if(st[i] >= 'A' && st[i] <='Z'){
      front.clear();
      front = st[i];
      operand.push_back(front);
    }else{
      if(st[i] == '('){
        oper.push('(');
      }else if(st[i] == ')'){
        while(oper.top() != '('){
          front.clear();
          back.clear();

          back = operand.back();
          operand.pop_back();
          front = operand.back();
          operand.pop_back();
          front = front +back +oper.top();
        //cout<<front<<endl;
          operand.push_back(front);

          oper.pop();
        }
        
        oper.pop();//괄호 없애기
      }else{
        oper.push(st[i]);
      }
    }
  }

  cout<<operand[0]<<endl;

  return 0;
}
