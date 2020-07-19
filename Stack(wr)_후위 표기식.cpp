//https://www.acmicpc.net/problem/1918

/*
  *와/ +와-의 우선순위를 생각을 못함.
  함수를 통해 우선순위를 계산할 수 있게 
*/

#include <iostream>
#include <stack>
#include<string>
using namespace std;

int order(char op){
  switch(op){
    case '*':
    case '/':
      return 2;
    break;
    case '+':
    case '-':
      return 1;
    break;

    default:
      return 0;
  }
}

int main() {
  string st;
  string post;
  stack<char> oper;
  char temp;
  cin>>st;

  st = '(' + st+ ')';

  for(int i=0; i<st.size() ; ++i){
    temp = st[i];
    if( temp>= 'A' && temp<= 'Z'){
      post= post + temp;
    }else{
      switch(temp){
        case '*':
        case '/':
        case '+':
        case '-':
          while(!oper.empty()&& order(oper.top())>= order(temp)){
            post= post + oper.top();
            oper.pop();
          }
          oper.push(temp);
        break;
        case '(':
          oper.push(temp);
        break;
        case ')':
          while(oper.top() != '('){
            post= post+ oper.top();
            oper.pop();
          }
          oper.pop();
        break;
      }
    }

  }

  cout<<post<<endl;

  return 0;
}

//
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
