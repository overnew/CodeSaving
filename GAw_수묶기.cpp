//https://www.acmicpc.net/problem/1744
//w는 wrong이라는 의미. 나중에 다시 보자

#include <iostream>
#include <algorithm>
using namespace std;

int seq[10000];

int main() {
  int n;
  int sum = 0;
  int left =0;
  
  cin>> n;
  int right =n-1;

  for(int i=0; i<n ; ++i){
    cin>>seq[i];
  }

  sort(seq, seq+n, greater<int>()); //내림차순
  
  for( ; left<right  ; left +=2 ){
    if(seq[left] >1 && seq[left+1] > 1){
      //1보다 크다면 모두 곱해주면됨
      sum += seq[left]* seq[left+1];
    }else
      break;
  }

  for( ; right >0 ; right -=2){
    if(seq[right] <1 && seq[right-1] <1){
      //1보다 작다면 0,-1~ 모두 곱해주면됨
      sum += seq[right] * seq[right-1];
    }else
      break;
  }

  for( ;right >=left ; --right ){
    sum += seq[right];
  }

  cout<<sum<<endl;

  return 0;
}
