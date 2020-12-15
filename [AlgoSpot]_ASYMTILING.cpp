//https://algospot.com/judge/problem/read/ASYMTILING
#include <iostream>
using namespace std;

int cache_tiling[101];
int cache_asym_tiling[101];
const int mod = 1000000007;

int main() {
  ios_base::sync_with_stdio(0);
  int test_num,rec_size;

  cin>>test_num;

  cache_tiling[1] = 1;
  cache_tiling[2] = 2;
  
  cache_asym_tiling[1]=0;
  cache_asym_tiling[2] = 0;

  for(int i=3; i<=100 ; ++i){
    cache_tiling[i] = (cache_tiling[i-1] + cache_tiling[i-2])%mod;
    if(i%2 ==1)  //홀수일 경우
      cache_asym_tiling[i] = (cache_tiling[i] - cache_tiling[i/2] + mod) %mod;
    else        //짝수인 경우
      cache_asym_tiling[i] = (((cache_tiling[i] - cache_tiling[i/2] +mod) % mod ) - cache_tiling[(i/2) -1] + mod) % mod;   
  }

  for(int i=0; i<test_num ; ++i){
    cin>>rec_size;
    cout<<cache_asym_tiling[rec_size]<<'\n';
  }

  return 0;
}
