//https://www.acmicpc.net/problem/1463


// 성공본 아래에서 위로 올라가는 걸로 바꿈(bottom-top 재귀가 핵심)
/*
아래에서부터 값을 저장. 즉 최소값만이 저장됨. 더 오래걸리는 방향에서도 최소값만을 참조하게되어 효과적.
ex) 1만 주구장창 뺄때 count는 치솟는데 최소값만을 저장한 캐쉬에 걸리면 최소값으로 바뀜. 어떤 캐쉬값에 접근하든 그것의 
Top buttom은 캐싱값에 최솟값이 안들어갈 수 있음. 근데 이걸 다시 다른 값이 최솟값으로 알고 참조하면서 오류가 걷잡을수 없이 커지게됨
*/

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

//실패 본 (top-down으로 사실상 부르트 포스나 )
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
