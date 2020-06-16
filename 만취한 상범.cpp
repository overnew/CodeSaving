//https://www.acmicpc.net/problem/6359
//왜안돼..

#include <iostream>
#include <string.h>
using namespace std;

bool cache[101][101];
int run[101];

void Whisky(){
  int sum;
  int n =100;

  for(int i=2; i<=2 ; ++i){
    sum=0;

      for(int k=1; k*i<=n ; ++k){
        cache[i][k*i] = !cache[i-1][k*i];
        cout<<cache[i][k*i] <<endl;
      }

    for(int j=1; j<=i ; ++j){
      if(cache[i][j]) {++sum;
        cout<<i<<", "<<j<<endl;
      }
    }
    run[i] = sum;
  }

}

int main() {
  int t,n;
  cin >> t;
  memset(cache, false ,sizeof(cache));//false가 닫힌거

  Whisky();

  for(int j=2; j<=100 ; ++j){
      cout<<"rum["<<j<<"]: "<<run[j]<<endl;
    }
  for(int i=0; i<t ; ++i){
    cin>> n;
    cout<<run[n]<<endl;
  }

  return 0;
}
