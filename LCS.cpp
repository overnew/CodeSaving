//사실상 다보고 푼거나 다름 없어.. 문자열의 풀이법에 익숙해지자
//https://www.acmicpc.net/problem/9251

#include <iostream>
#include <string>
#include <string.h>
using namespace std;

int cache[1000][1000]

int main() {
  string a,b;
  cin>>a>>b;

  memset(cache, 0, sizeof(cache))
  for(int i=0; i<b.length() ; ++i){
    if(a[0] == b[i]) ++cache[0][i];
  }
  for(int i=1; i< a.length() ; ++i){
    if(a[i]==b[0]) ++cache[i][0];
    for(int j=1; j<b.length()  ;++j ){
      if(cache[i-1][i-1])
      if(a[i] == b[j]) cache[i][j] = cache[i-1][i-1] + 1;
      else cache[i][j] = cache[i-1][i-1];
    }
  }
  
  return 0;
}
