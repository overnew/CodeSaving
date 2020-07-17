//https://www.acmicpc.net/problem/10799
/*
  문자열에서 하나씩 조건문을 돌게 한다. '(' 는 ')'가 나오면 pop을 하는 형식
  막대를 지나는 선의 개수 +1이 막대가 나눠지는 개수이므로 막대가 시작됬을 때의 레이저 개수와 끝날때의 개수를 빼주고 +1을 하면됨.
*/

#include <iostream>
#include<stack>
#include<string>
using namespace std;

int main() {
  string stick;
  stack<char> st;
  stack<int> rager;
  int rag=0;
  int sum =0;

  cin>>stick;

  for(int i=0; i<stick.size() ; ++i){
    if(stick[i] == '('){
      st.push(stick[i]);
      rager.push(rag); 
    }else{//stick[i] == ')'인 경우
      if(rag == rager.top()){ //레이저인 경우
        rag++;
        st.pop();
        rager.pop();
      }else{
        st.pop();
        sum +=( (rag - rager.top()) +1 );
        rager.pop();
      }
      
    }
  }

  cout<<sum<<endl;

  return 0;
}
