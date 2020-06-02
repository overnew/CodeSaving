//https://www.acmicpc.net/problem/9095
//쉬운 동적 계획. 바텀 탑을 지향해서 아래의 값을 재사용

#include <iostream>
#include <vector>
#include<string.h>
using namespace std;

int cache[12];

int Onetwo(int n){
  if(n== 0) return 1;

  int& ret = cache[n];
  if( ret != -1) return ret;

  ret = 0; // 0으로 초기화 해줘야 값을 쌓을 수 이쓰
  if(n >=3) ret += Onetwo(n-3);
  if(n>=2) ret += Onetwo(n-2);
  ret += Onetwo(n-1);

  return ret;
}

int main() {
  int T,temp;
  cin>> T;
  vector<int> arr;
  memset(cache,-1,sizeof(cache));

  for(int i=0;i <T ; ++i){
    cin>>temp;
    arr.push_back(temp);
  }

  for(int i=0;i<T ; ++i){
    cout<<Onetwo(arr[i])<<endl;
  }
  
  return 0;
}
