//https://www.acmicpc.net/problem/1541
// -가 하나라도 나오면 그 다음은 다 빼버리면 됨

#include <iostream>
#include <string>
using namespace std;

int idx= 0;
string a;

int GetNumber(){ //연산자의 앞에 나오는 수를 가져옴
  int sum=0;
  for( ; a[idx] != '-' && a[idx] != '+' && idx<a.length()  ; ++idx){
    sum *= 10;
    sum += (a[idx] -'0');
  }
  return sum;
}

int main() {
  int sum =0;
  int temp;
  bool minus = false;
  idx = 0;

  cin>>a;

  for(; idx<a.length()  ;++idx){
    temp = GetNumber();

    if(minus){
      sum -= temp;
    }else{
      if(a[idx] == '-') minus = true;
      sum += temp;
    }
  }

  cout<<sum<<endl;

  return 0;
}
