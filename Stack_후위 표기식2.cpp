//https://www.acmicpc.net/problem/1935

/*
  c++에서의 소수점 출력은
  cout<<fixed;
  cout.precision(n); 을 통해 n자리 수까지만 출력하게 설정할 수 있다.
  
  피연산자는 스택에 쌓고 연산자가 나올때마다 두개를 꺼내서 계산후 다시 집어넣는 것을 반복하면 된다.
*/

#include <iostream>
#include<string>
#include<stack>
using namespace std;

double calcul(double a, double b, char temp){
  switch(temp){
    case '*':
    return a*b;
    break;

    case '/':
      return a/b;
    break;

    case '+':
      return a+b;
    break;

    case '-':
      return a-b;
    break;
  }

  return 0;
}

int main() {
  int arr[26];
  int n;
  double fr,se;
  char temp;
  string st;
  stack<double> rand;

  cin>>n>>st;

  for(int i=0; i<n ; ++i){
    cin>>arr[i];
  }

  for(int i=0; i<st.size() ; ++i){
    temp = st[i];
    if(temp >= 'A' && temp <= 'Z'){
      rand.push(arr[temp -'A']); //arr순서대로 넣기
    }else{
      se = rand.top();
      rand.pop();
      fr = rand.top();
      rand.pop();
      rand.push(calcul(fr, se, temp));
    }
  }

  cout<<fixed;
  cout.precision(2);
  cout<<rand.top()<<endl;

  return 0;
}
