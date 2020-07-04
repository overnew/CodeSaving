//https://www.acmicpc.net/problem/4948

#include <iostream>
#include <string.h>
#include <cmath>
using namespace std;

const int MAX = 2*123456; //두배니까 2곱해야 
bool prime[MAX +1]; 

int main(){
  int i,j,n;
  int count=0;
  int sqrtn = int(sqrt(MAX));
  memset(prime,true, sizeof(prime));
  prime[0] =prime[1]= false;

  for(i=2; i<=sqrtn ;++i )
    if(prime[i])
      for(j=i*i; j<=MAX ; j+=i)
        prime[j] = false;
  
  while(true){
    cin>>n;
    if(n==0) break;

    count =0;

    
    for(i=n+1 ; i<=(2*n) ;++i){ //i+=2로 최적화 해봤는데 이상하게 틀린다.
      if(prime[i])
        ++count;
    }
    cout<<count<<endl;
  }

  return 0;
}
