//https://www.acmicpc.net/problem/9251
// 동적 계획법.. 다 보고했구만..
//두 문자열을 행렬로 만들고 겹치는 것이 나올때마다 행렬에 변화를 줌

#include <iostream>
#include <string>
#include <string.h>
using namespace std;

int cache[1001][1001];

int main() {
  string a,b;
  string zero("0");
  int max = 0;

  memset(cache, 0 ,sizeof(cache));
  cin>> a>> b;
  b = zero +b; // 0을 앞에 넣어두면 배열의 첫번째는 위옆이 없어 예외 처리 해야하는 것을 방지할 수 있음
  a = zero + a;

  for(int i=1; i<a.length() ; ++i){
    for(int j=1 ; j<b.length() ; ++j){
      if(b[j] == a[i]){
        cache[i][j] = cache[i-1][j-1] + 1;
      }else{
        cache[i][j] = cache[i-1][j]> cache[i][j-1] ? cache[i-1][j] : cache[i][j-1];
      }
    }
  }

  for(int i=1; i<a.length() ; ++i){
    max = max > cache[i][b.length()-1]? max:cache[i][b.length()-1]; //행의 끝과 열의 끝에서의 최대값이 결과적으로 lcs일 수 밖에 없음
  }

  for(int i=1; i<b.length() ; ++i){
    max = max > cache[a.length()-1][i]? max:cache[a.length()-1][i];
  }

  cout<<max<<endl;

  return 0;
}

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
