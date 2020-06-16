//https://www.acmicpc.net/problem/5582
//문자열의 동적계획법을 익히니 쉬었음. 일단 각 행렬로 매트릭스를 만든다.
//문자가 동일하다면 자신의 왼쪽위의 값에 +1 한것이 이어지는값으로 해결~, 동일하지 않으면 아무 상관없음.

#include <iostream>
#include <string>
#include<string.h>
using namespace std;

int cache[4001][4001];

int main() {
  int max = 0;
  string a, b;
  string zero("0");
  cin>>a>>b;

  a = zero +a;
  b= zero +b;

  memset(cache, 0 ,sizeof(cache));

  for(int i = 1; i<a.length() ; ++i){
    for(int j=1 ; j<b.length() ; ++j){
      if(a[i] == b[j]){
        cache[i][j] = cache[i-1][j-1] +1;
        max = cache[i][j] > max ? cache[i][j]: max;
      }
    }
  }

  cout<< max<<endl;

  return 0;
}
