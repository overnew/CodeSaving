//https://www.acmicpc.net/problem/11049
//처음에는 4개의 행렬에서의 5가지 분기 경우를 해보려 했는데 5개에서는 또 중복되지 않는 경우가 나옴
// 단순히 for문으로 2가지 묶음으로 나누는 반복문으로도 해결가능(1개와 나머지 와 같은것도 두가지 묶음으로 치면 가능)
//특히 맨처음과 맨끝의 r,c만 알면 되기에 동적계획이 가능했음

#include <iostream>
#include <string.h>
#include <limits.h>
using namespace std;

int N;
int matrix[500][2];
int cache[500][500]; //[x][y] x~y까지의 행렬곱셈의 최소값

int Order(int x, int y){
  int n = y-x;
  int min = INT_MAX;
  int m;

  if(n==0) return 0;

  int& ret = cache[x][y];
  if(ret != -1) return ret;

  

  for(int i=x; i<y ; ++i){ //분류의 경우를 모두
    m = Order(x,i) + Order(i+1,y) + matrix[x][0]*matrix[i][1] * matrix[y][1];
    min = m<min ? m : min;
  }
  ret = min;

  return ret;
}

int main() {
  cin>> N;

  memset(cache, -1, sizeof(cache));
  for(int i=0; i<N ; ++i){
    cin>> matrix[i][0] >> matrix[i][1];
  }

  cout<< Order(0,N-1)<<endl;

  return 0;
}
