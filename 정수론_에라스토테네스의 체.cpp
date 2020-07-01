//https://www.acmicpc.net/problem/2960
//이 문제는 제곱근을 쓰면 안되는데 써서 틀림

#include <iostream>
#include <string.h>
using namespace std;

int main() {
  int is_prime[1001];
  int n,k;
  int count=0;
  int erase_num=-1;

  cin>>n>>k;
  memset(is_prime,true, sizeof(is_prime));

  is_prime[0] = is_prime[1] = false;

  for(int i=2; i<=n ; ++i){
    if(is_prime[i]){

      is_prime[i] = false;
      if((++count) == k){
        erase_num = i;
        break;
      }

      for(int j = i*i; j<=n ; j+=i ){
        if(is_prime[j]){
          is_prime[j] = false;
          if((++count) == k){
            erase_num = j;
            break;
          }
        }
      }
      if(erase_num != -1)
        break;
    }
  }

  cout<< erase_num<<endl;

  return 0;
}
