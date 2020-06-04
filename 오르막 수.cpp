//https://www.acmicpc.net/problem/11057
//아래보단 빠를것 같은데 나머지 연산이 안되서 수정 => > 빼기연산에서는 나머지 연산이 큰 오류! 나머지 연산때문에 더크던 값이 빼는 값보다 
//작아저서 마이너스가 나옴

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
    reuse[2] += cache[2][i];
  }

  for(int i=3; i<=n ; ++i){
    reuse[i] =0;
    cache[i][0] = reuse[i-1];
    for(int j=0; j<9 ; ++j){
      cache[i][j+1] = cache[i][j] - cache[i-1][j];
    }
    for(int j=0; j<9 ; ++j){
      reuse[i] += (cache[i][j])%10007;
    }
    reuse[i]%=10007;
  }

  int sum=0;

  for(int i=1 ; i<=n ; ++i){
    sum += reuse[i];
    sum %= 10007;
  }

  return sum;
}

int main(){
  int n;
  cin>> n;

  cout<<Climb(n)<<endl;

  return 0;
}

// 이전값들을 불러와 하나씩 빼지 않고 3중 포문으로 앞에거를 제외시키며 더하는 코드는 10007나머지 연산이 쉽게가
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
    reuse[2] += cache[2][i];
  }

  for(int i=3; i<=n ; ++i){
    reuse[i] =0;
    for(int j=0; j<9 ; ++j){
        cache[i][j] =0;
      for(int k=j ; k<9 ;++k){
        cache[i][j] = (cache[i][j]+ cache[i-1][k]) % 10007;
      }
      reuse[i] = (reuse[i] + cache[i][j]) %10007;
    }
  }

  int sum=0;

  for(int i=1 ; i<=n ; ++i){
    sum  = (sum+  reuse[i])%10007;
  }

  return sum;
}

int main(){
  int n;
  cin>> n;

  cout<<Climb(n)<<endl;

  return 0;
}
