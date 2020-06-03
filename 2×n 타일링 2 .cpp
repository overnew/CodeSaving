//https://www.acmicpc.net/problem/11727
//굉장히 이상하게 조합까지 계산하며 품.. 계산은 맞는데 10007의 나머지 연산이 적용이 안되는 코드라 쉬운걸로 풀게됨

#include <iostream>
#include <string.h>
using namespace std;

int cache[1001][1001]; //[][0]은 일반 타일의 방법수
int combi[1001][1001];
int sum_sombi[1001];

int Tiling(int n){
  cache[1][0] =1;
  cache[2][0] = 2; cache[2][1] =1;
  int result =0;

  for(int i=3; i<=n ; ++i){
    cache[i][0] = cache[i-1][0] + cache[i-2][0];
  } // 


  for(int i=3 ; i<=n ;++i ){
    int sum=0;
    for(int j =1 ; cache[i-2][j] !=0 ;++j){
      sum += cache[i-2][j];
    }
    cache[i][1] = cache[i-2][0] - sum;

    for(int j=1 ; cache[i-2][j]!=0 ;++j){
      cache[i][j+1] = cache[i-2][j];
    }

    for(int j=1 ; cache[i-1][j] !=0 ;++j ){
      cache[i][j] += cache[i-1][j];
    }
  }
  combi[1][0] =1; combi[1][1]=1;

  for(int i=2; cache[n][i] !=0 ; ++i){
    combi[i][0] = 1; combi[i][i]=1;
    for(int j=1 ; j<i ; ++j){
      combi[i][j] = combi[i-1][j-1] + combi[i-1][j];
    }
  }
  for(int i=1 ; cache[n][i] !=0 ;++i){
    for(int j=0 ; j<i ; ++j){
      sum_sombi[i] += combi[i][j];
    }
  }
  result += cache[n][0];
  for(int i=1 ; cache[n][i] !=0 ;++i){
    result += (cache[n][i]*sum_sombi[i]);
    //result %= 10007;
  }
  return result%10007;
}

int main() {
  int n;
  cin>> n;

  memset(cache, 0 ,sizeof(cache));
  memset(combi, -1, sizeof(combi));
  memset(sum_sombi, 0 ,sizeof(sum_sombi));

  cout<<Tiling(n)<<endl;

  return 0;
}

//쉬운코드
#include <iostream>
#include <string.h>
using namespace std;

int cache[1001];

int Tiling(int n){
  cache[1] =1;
  cache[2] =3;

  for(int i=3 ; i<= n ;++i){
    cache[i] = (cache[i-2]*2 + cache[i-1]) %10007; //이렇게 2만 곱해줘도 사실상 모두 대응
  }

  return cache[n];
}

int main() {
  int n;
  cin>> n;


  cout<<Tiling(n)<<endl;

  return 0;
}
