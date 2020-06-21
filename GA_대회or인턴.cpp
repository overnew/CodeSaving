//https://www.acmicpc.net/problem/2875
//탐욕법. 모든 경우를 if로 처리해 버림.
/*
  여자가 남자x2보다 많으면 일단 여자에서 인턴쉽을 보내고
  반대면 차이만큼 남자를 보낸 후 계산하면 됨. 
  
  다른 알고리즘은 팀(t)을 1부터 카운트 해서 limit = n+m-k;를 넘지 않을때까지 ++t로 팀수를 올리며 계산
*/

#include <iostream>
using namespace std;

int main() {
  int n,m,k;
  int result;
  cin>>n>>m>>k;

  int gap= n - 2*m;
  int max_team;
  if( gap > 0 ){
    if(k<=gap)
      result = m;
    else{
      k -= gap;
      if(k%3 ==0){
        result = m- k/3;
      }else{
        result = (m- k/3) - 1;
      }
    }
  }else if(gap == 0){
    if(k%3 ==0){
      result = m- k/3;
    }else{
      result = (m- k/3) - 1;
    }
  }else{ // gap<0 =>남자가 더 많음.
    int mem = m - (n/2);
    if(k<= mem)
      result = n/2;
    else{
      k -= mem;
      m -= mem;
      k -= n%2;
      if(k%3 ==0){
        result = m - k/3;
      }else{
        result = (m- k/3) - 1;
      }
    }
  }

  cout<< result<<endl;

  return 0;
}
