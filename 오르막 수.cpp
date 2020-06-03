//뭔가 잘못됨
//https://www.acmicpc.net/problem/11057

#include<iostream>
using namespace std;

int cache[1001][11];
int reuse[1001];

int Climb(int n){

  for(int i=0; i<10 ; ++i){
    cache[1][i] = i+1;
  }
  reuse[1] =10;

  reuse[2] = 0;
  for(int i=0; i<9 ; ++i){
    cache[2][i] = 10-(i+1);
    reuse[2] += cache[1][i];
  }
  reuse[2] +=10 ;

  for(int i=3; i<=n ; ++i){
    reuse[i] =0;
    cache[i][0] = reuse[i-1];
    for(int j=0; j<9 ; ++j){
      cache[i][j+1] = cache[i][j] - cache[i-1][j];
    }
    for(int j=0; j<9 ; ++j){
      reuse[i] += cache[i][j];
      cout<< cache[i][j]<<endl;
    }
  }

  return reuse[n];
}

int main(){
  int n;
  cin>> n;

  cout<<Climb(n)<<endl;

  return 0;
}
