//https://www.acmicpc.net/problem/9252
//캐쉬값을 따라 올라가며 저장하면 됨.

#include <iostream>
#include <string>
#include <string.h>
using namespace std;

int cache[1001][1001];

int main() {
  string a,b;
  string zero("0");

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


  cout<<cache[a.length()-1][b.length()-1]<<endl;

  string b_l;
    int j= b.length()-1;

    for(int i=a.length()-1 ; i>0 ; --i){

      if(cache[i][j] != cache[i-1][j]){
        while(cache[i][j] ==cache[i][j-1]) --j;

        b_l.push_back(b[j]);
        --j;
      }

    }

  for(int i=b_l.length()-1 ; i>=0 ; --i){
    cout<<b_l[i];
  }
  cout<<endl;

  return 0;
}
