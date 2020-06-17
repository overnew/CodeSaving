//https://www.acmicpc.net/problem/2156
//동적 계획법. 생각나는 대로 처음에는 one과 two만 생각했지만
//https://mygumi.tistory.com/98에서 나오듯 100, 400, 2, 1, 4, 200가 주어지면 100, 400, 4, 200처럼 두칸을 안먹어야
//최대인 경우가 있다. 따라서 no = Drink(n+1) 처럼 한 칸을 그냥 안먹고 띄어 주는 경우도 추가해주어야 한다. 이런 예외 케이스.. 어렵다
//재귀가 아닌 for문으로도 충분이 풀이 가능하니 생각하도록

#include <iostream>
#include <string.h>
using namespace std;

int N;
int wine[10001];
int cache[10001];

int Drink(int n){ //n부터 N까지
  int one=0 ,two =0, no=0;
  if(n>N) return 0;
  if(n==N) return wine[N];

  int& ret = cache[n];
  if(ret != -1) return ret;

  one = wine[n] + Drink(n+2); //한칸씩 띄우기
  two = wine[n] + wine[n+1] + Drink(n+3);
  no = Drink(n+1);

  one = one> no ? one : no;

  ret = one> two ? one : two;

  return ret;
}

int main() {
  int max, one, two;
  cin>>N;

  memset(cache, -1, sizeof(cache));

  for(int i=1; i<=N ; ++i){
    cin>>wine[i];
  }

  cout<< Drink(1)<<endl;

  return 0;
}
