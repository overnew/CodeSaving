//https://www.acmicpc.net/problem/1463


// 성공본 아래에서 위로 올라가는 걸로 바꿈
#include <iostream>
#include<string.h>
using namespace std;

int cache[1000001];

int MakeOne(int n){
  int meth[3] = {1000000,1000000,1000000};
  int a,b;

  if(n == 1) return 0;

  int& ret = cache[n];

  if( ret != -1) return ret;

  if(n%3 == 0)
    meth[0]=MakeOne(n/3) +1;
  
  if(n%2 == 0)
    meth[1]=MakeOne(n/2)+1;

  meth[2]=MakeOne(n-1) +1;

  a = meth[0] < meth[1] ? meth[0] : meth[1];
  b = meth[1] < meth[2] ? meth[1] : meth[2];
  ret = a < b ? a: b;

  return ret;
}

int main() {
  int n;
  cin >> n;

  memset(cache, -1, sizeof(cache));


  cout <<MakeOne(n)<<endl;

  return 0;
}

//실패 본
#include <iostream>
#include<string.h>
using namespace std;

int cache[1000000];

int MakeOne(int n, int count){
  int meth[3] = {1000000,1000000,1000000};
  int a,b;

  if(n == 1) return count;

  int& ret = cache[n];

  if( ret<=count  && ret != -1) return ret;

  if(n%3 == 0)
    meth[0]=MakeOne(n/3, count+1);
  
  if(n%2 == 0)
    meth[1]=MakeOne(n/2, count +1);

  meth[2]=MakeOne(n-1, count +1);

  a = meth[0] < meth[1] ? meth[0] : meth[1];
  b = meth[1] < meth[2] ? meth[1] : meth[2];
  ret = a < b ? a: b;

  return ret;
}

int main() {
  int n;
  cin >> n;

  memset(cache, -1, sizeof(cache));


  cout <<MakeOne(n,0)<<endl;

  return 0;
}
