//https://www.acmicpc.net/problem/4949

//yes와 no를 대문자로 출력해서 틀림 

#include <iostream>
#include<string>
#include<stack>
using namespace std;

int main() {
  ios_base::sync_with_stdio(0);

  while(1){
    string st;
    stack<char> pet;
    getline(cin,st);

    if(st.size() ==1 && st[0] =='.')
      break;

    int i=0;
    for(; i<st.size() ; ++i){

      if(st[i] == '(' || st[i] =='['){
        pet.push(st[i]);

      }else if(st[i] == ')'){
        if(!pet.empty() &&pet.top() == '(')
          pet.pop();
        else
          break;
      }else if(st[i] == ']'){
        if(!pet.empty() && pet.top() == '[')
          pet.pop();
        else
          break;
      }
    }

    if(i == st.size() && pet.empty())
      cout<<"yes\n";
    else
      cout<<"no\n";

  }

  return 0;
}
