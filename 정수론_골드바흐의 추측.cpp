//https://www.acmicpc.net/problem/6588
//되다가 시간초과..

#include <iostream>
#include <string>
#include <string.h>
#include <cmath>
#include <vector>
#include <algorithm>
#include <stdio.h>
using namespace std;

const int MAX_NUM = 1000000;
int prime[MAX_NUM+1];
vector<int> pri;

int main() {
  int j;
  int num;
  int temp;
  string wrong ="Goldbach's conjecture is wrong.";
  memset(prime, true, sizeof(prime));
  prime[0] = prime[1] = false;
  int sqrtn = int(sqrt(MAX_NUM));

  for(int i=2; i<=sqrtn ; ++i){
    if(prime[i])
      for(j =i*i; j<=MAX_NUM ; j+=i)
        prime[j] = false;
  }

  for(int i=3; i<=MAX_NUM ; ++i){
    if(prime[i]){
      pri.push_back(i);
    }
  }

  vector<int>::iterator iter;

  while(true){
    cin>>num;
    if(num == 0) break;

    for(int i=0; i<pri.size() ; ++i){
      if(pri[i]> (num/2) ) {
        cout<<wrong<<endl;
        break;
      } //이이상을 볼 필요는 없음
      temp = num;
      temp -= pri[i];
      iter = find(pri.begin(),pri.end(),temp);
      if(iter == pri.end())
        continue;
      else{
        printf("%d = %d + %d\n",num,pri[i],temp);
        break;
      }
    }

  }

  return 0;
}
