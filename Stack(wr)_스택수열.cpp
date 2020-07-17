//https://www.acmicpc.net/problem/1874

/*
  endl을 출력에 사용하고 bool로 저장한후 true면 +를 출력하게 했더니 시간초과
  endl을 '\n'으로 작성하는 습관을 들이자.(두 부분을 바꿧더니 바로됨.)
  
  sol[i] <sol[i+1] 이면 i+1만큼 push해준후 윗값을 pop하고
  else 이면 top이 sol[i+1]라면 pop, 아니라면 불가능
*/

#include <iostream>
#include <stack>
using namespace std;

int sol[100000];
char answer[100000];

int main() {
  int n,j,max;
  bool pos = true;
  int idx=0;
  stack<int> arr;
  cin>>n;
  ios_base::sync_with_stdio(0);

  for(int i=0; i<n ; ++i)
    cin>>sol[i];

  for(int i=1; i<=sol[0] ; ++i){
    arr.push(i);
    answer[idx++] = '+'; //push를 의미
  }
  arr.pop();
  answer[idx++] = '-';

  max = sol[0];
  
  for(int i=0; i<n-1 ; ++i){
    if(sol[i] <sol[i+1]){
      for(j=max+1; j<=sol[i+1] ;++j ){
        arr.push(j);
        answer[idx++] = '+';
      }
      max = sol[i+1];
      arr.pop();
      answer[idx++] = '-';
    }else{ //sol[i] >sol[i+1]
      if(arr.top() == sol[i+1]){
        arr.pop();
        answer[idx++] = '-';
      }else{
        pos = false;
        break;
      }
    }
  }

  if(!pos){
    cout<<"NO"<<'\n';
  }else{
    for(int i=0; i<idx ; ++i){
      cout<<answer[i]<<'\n';
    }
  }

  return 0;
}
