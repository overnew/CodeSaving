//https://www.acmicpc.net/problem/10610
//너무 깊게 생각함.
//30의 배수는 0이 있어야하고, 각 자리수들의 합이 3의 배수면 됨.(3의 배수의 특징)
//두 조건만 성립하면 0이 앞에 있기만 하면 30의 배수이기 때문에 그냥 내림차순으로 정리하면됨.
// 그리고 계속 num[i] = n[i] -'0'; 처럼 문자열에서 수를 가져올때 -'0'를 빼먹어서 오류가 나오니 조심하자

#include <iostream>
#include<string>
#include <algorithm>
using namespace std;

int num[100000];

int main() {
  string n;
  int sum=0;

  cin>>n;

  for(int i=0; i<n.length() ; ++i){
    num[i] = n[i] -'0';
  }

  sort(num, num+n.length(), greater<int>()); 
  
  //내림차순
  if(num[n.length() -1] != 0){ //0이 없으면 불가능
    cout<<-1<<endl;
    return 0;
  }

  for(int i=0; i<n.length() ; ++i){
    sum += num[i];
  }

  if(sum %3 !=0){
    cout<<-1<<endl;
    return 0;
  }

  for(int i=0; i<n.length() ; ++i){
    cout<<num[i];
  }
  cout<<endl;

  return 0;
}
