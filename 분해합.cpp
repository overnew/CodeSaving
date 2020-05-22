//https://www.acmicpc.net/problem/2231
//쉬웠던 

#include <iostream>
#include <algorithm>

using namespace std;
int N;
int jari=0;
int digit[7];

int disSum(){
  int poss= 9*jari;
  int min = N - poss;
  int temp = min;
  int answer=0;

  while(min < N){
    temp = min;
    for(int i=0; i<jari ; ++i){
    
    digit[i] = temp%10;
    temp = temp/10;
    answer += digit[i]; 
    }
    answer += min;

    if(answer == N)
      return min;
    answer =0;
    ++min;
  }
  return 0;
}

int main() {
  cin>>N;
  int temp = N;

  for(int i=0; i<7 ; ++i){
    digit[i] = temp%10;
    temp = temp/10;
    if(temp == 0){
      jari = i+1;
      break;
    }
  }
  
  cout<< disSum()<<endl;

  return 0;
}
