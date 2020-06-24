//https://www.acmicpc.net/problem/1744

#include <iostream>
#include <algorithm>
using namespace std;

int seq[10000];

int main() {
  int n;
  int sum = 0;
  bool plus =true;
  bool minus = true;
  int plus_end= -1;
  int minus_start=-1; //-1이면 값이 안들어 간것
  cin>> n;

  for(int i=0; i<n ; ++i){
    cin>>seq[i];
  }

  sort(seq, seq+n, greater<int>()); //내림차순
  
  for(int i=0 ; i<n ; ++i){
    
    if(minus && seq[i]<0){
      minus_start =i;
      minus = false;
    }else if(plus && seq[i]<1){ 
      plus_end = i;
      plus = false;
    }

    if(i == n-1){
      plus_end = n;
    }
  }

  if(plus_end != -1)
  for(int i=0; i<plus_end ; i+=2){
    if(seq[i] != 1 && i+1<plus_end && seq[i+1] != 1){
      seq[i] *= seq[i+1];
      seq[i+1] = 0;
    }
  }

  if(minus_start != -1)
  for(int i=n-1; i>=minus_start ; i-=2){
    if(i-1>=minus_start){
      seq[i] *= seq[i-1];
      seq[i-1] = 0;
    }
  }

  if((n-minus_start)%2 != 0){
    if(plus_end != minus_start)
      seq[minus_start] = 0;
  }

  for(int i=0; i<n ; ++i){
    cout<<"seq["<<i<<"]: " <<seq[i]<<endl;
    sum+= seq[i];
  }

  cout<< sum<<endl;

  return 0;
}
