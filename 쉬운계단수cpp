//동적 계획. 처음에는 전체 합으로만 [i]와 [i-1]의 관계식만 을 찾으려한게 패인이였다.
//피보나치문제들 땜에 이런식으로 관계식을 찾으려는게 문제.
// 단순히 각 자리마다 0~9의 개수를 세고 다음 0과 9가 만들어지는 1과 8만 제외하고 두배씩 늘려주면된다.
//이런걸 슬라이딩 기법이라고 한다드라
//https://www.acmicpc.net/problem/10844

#include <iostream>
using namespace std;

int N;
int cache[101][10];

int Stair(){
  for(int i=0; i<10 ; ++i){
    cache[1][i] = 1;
  }
  cache[1][0] = 0;

  for( int  i=2 ; i<=N ; ++i){
    cache[i][0] = cache[i-1][1];
    for(int j=1 ; j<9 ; ++j){
      cache[i][j] = (cache[i-1][j-1] + cache[i-1][j+1])%1000000000;
    }
    cache[i][9] = cache[i-1][8];
  }

  int sum =0;
  for(int i=0; i<10 ; ++i){
    sum = (sum + cache[N][i])%1000000000;
  }
  return sum;
}

int main() {
  cin>> N;

  cout<< Stair()<<endl;
  return 0;
}

//틀렸으니 수정. 접근

#include <iostream>
using namespace std;

int cache[101];

int Stair(int n){
  cache[1] = 9;
  cache[2] = 17;

  for(int i=3 ; i<=n ; ++i){
    cache[i] = ((cache[i-1] -2)*2 + 2)%1000000000;
  }
  return cache[n];
}

int main() {
  int n;
  cin>> n;

  cout<<Stair(n) <<endl;

  return 0;
}
