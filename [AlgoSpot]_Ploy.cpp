//https://algospot.com/judge/problem/read/POLY
#include <iostream>
#include<string.h>
using namespace std;

int square_num;
const int mod = 10000000;
int cache[101][101];

int PloyCount(int remain_squ, int pre_squ){
  if( remain_squ <=0)
    return 1;

  int& ret = cache[remain_squ][pre_squ];
  if(ret != -1)
    return ret;
  
  ret =0;
  for(int num= 1; num<=remain_squ ; ++num){
    if(pre_squ == 0)
      ret += PloyCount(remain_squ-num,num);
    else
      ret += (pre_squ +num -1) * PloyCount(remain_squ-num,num);
    ret %=mod;
  }

  return ret;
}

int main() {
  ios_base::sync_with_stdio(0);
  
  int test_num;
  cin>>test_num;

  for(int i=0; i<test_num ; ++i){
    cin>>square_num;

    memset(cache, -1, sizeof(cache));
    cout<<PloyCount(square_num, 0)<<'\n';
  }

  return 0;
}
